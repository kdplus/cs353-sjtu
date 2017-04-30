#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/sem.h>
#include <linux/list.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/vmalloc.h>
#include <linux/highmem.h>
#define MAX_BAKA 10
#define current get_current()
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Mika");

// module_param
static int baka_num;
module_param(baka_num, int, 0644);
static char *namae = "Baka!\0";
module_param(namae, charp, 0644);
static int bakas[MAX_BAKA];
static int nr_baka = 0;
module_param_array(bakas, int, &nr_baka, 0664);


// static int(*oldcall)(void);
struct proc_dir_entry *test_dir, *test_file;

char *baka_name = "Tadano Baka\0";
static int mika_proc_show(struct seq_file *m, void *v) {
    seq_printf(m, "%s\n", baka_name);
    return 0;
}


static void list_vma(void) {
    struct mm_struct *mm = current->mm;
    struct vm_area_struct * vma;
    printk(KERN_INFO "Current process is %s.\n", current->comm);
    down_read(&mm->mmap_sem);
    for (vma = mm->mmap; vma; vma = vma->vm_next) {
        char vma_result[1000];
        int offset = 0;
        offset += sprintf(vma_result, "VMA 0x%lx-0x%lx ", vma->vm_start, vma->vm_end);
        if (vma->vm_flags & VM_WRITE) offset += sprintf(vma_result+offset, "w");
        if (vma->vm_flags & VM_READ) offset += sprintf(vma_result+offset, "r");
        if (vma->vm_flags & VM_WRITE) offset += sprintf(vma_result+offset, "e");
        printk(KERN_INFO "%s\n", vma_result);
    }
    up_read(&mm->mmap_sem);
}


static struct page *mika_follow_page(struct vm_area_struct *vma, unsigned long addr) {
    pud_t *pud;
    pmd_t *pmd;
    pgd_t *pgd;
    pte_t *pte;
    spinlock_t *ptl;
    int flag = 0;
    struct page *page = NULL;
    struct mm_struct *mm = vma->vm_mm;
    pgd = pgd_offset(mm, addr);
    /*
    if (flag == 0 && (pgd_none(*pgd) || unlikely(pgd_bad(*pgd)))) flag = -1;
    printk("pgd %d\n", pgd_none(*pgd));
    if (flag == 0) pud = pud_offset(pgd, addr);
    if (flag == 0 && (pud_none(*pud) || unlikely(pud_bad(*pud)))) flag = -1;
    printk("pud %d\n", flag);
    if (flag == 0) pmd = pmd_offset(pud, addr);
    if (flag == 0 && (pmd_none(*pmd) || unlikely(pmd_bad(*pmd)))) flag = -1;
    printk("pmd %d\n", flag);
    if (flag == 0) pte = pte_offset_map_lock(mm, pmd, addr, &ptl);
    if (flag == 0 && !pte) flag = -1;
    if (flag == 0 && !pte_present(*pte)) flag = 1;
    printk("pte %d\n", flag);
    if (flag == 0) page = pfn_to_page(pte_pfn(*pte));
    if (flag == 0 && !page) flag = 1;
    printk("page %d\n", flag);
    if (flag == 0) get_page(page);
    if (flag == 1) pte_unmap_unlock(pte, ptl);
    return page;
*/
    if (pgd_none(*pgd) || unlikely(pgd_bad(*pgd))) goto out;
    pud = pud_offset(pgd, addr);
    if (pud_none(*pud) || unlikely(pud_bad(*pud))) goto out;
    pmd = pmd_offset(pud, addr);
    if (pmd_none(*pmd) || unlikely(pmd_bad(*pmd))) goto out;
    pte = pte_offset_map_lock(mm, pmd, addr, &ptl);
    if (!pte) goto out;
    if (!pte_present(*pte)) goto unlock;
    page = pfn_to_page(pte_pfn(*pte));
    if (!page) goto unlock;
    get_page(page);
unlock:
    pte_unmap_unlock(pte, ptl);
out:
    return page;
}


static void mika_write_val(unsigned long addr, unsigned long val) {
    struct vm_area_struct *vma;
    struct mm_struct *mm = current->mm;
    struct page *page;
    unsigned long kernel_addr;
    printk(KERN_INFO "Mika write value ...\n");
    down_read(&mm->mmap_sem);
    vma = find_vma(mm, addr);
    if (vma && addr >= vma->vm_start && (addr + sizeof(val)) < vma->vm_end) {
        if (!(vma->vm_flags & VM_WRITE)) {
            printk(KERN_INFO "You don't right of writing\n");
            goto out;
        }
        page = mika_follow_page(vma, addr);
        if (!page) {
            printk(KERN_INFO "Page not found for 0x%lx\n", addr);
            goto out;
        }
        kernel_addr = (unsigned long) page_address(page);
        kernel_addr += (addr & ~PAGE_MASK);
        *(unsigned long*)kernel_addr = val;
        put_page(page);
        printk(KERN_INFO "Writing %lx into address 0x%lx\n", val, addr);
    } else {
        printk(KERN_INFO "No VMA for this address\n");
    }
out:
    up_read(&mm->mmap_sem);
}


static void find_page(unsigned long addr) {
    struct vm_area_struct *vma = NULL;
    struct mm_struct *mm = current->mm;
    unsigned long kernel_addr = 0;
    struct page *page;

    printk(KERN_INFO "Result of findind page for %lx:\n", addr);
    down_read(&mm->mmap_sem);
    vma = find_vma(mm, addr);
    page = mika_follow_page(vma, addr);
    if (!page) {
        printk(KERN_INFO "Translation not found!\n");
    } else {
        kernel_addr = (unsigned long) page_address(page);
        kernel_addr += (addr & ~PAGE_MASK);
        printk(KERN_INFO "It's kernel address is 0x%lx\n", kernel_addr);
    }
    up_read(&mm->mmap_sem);
}


static ssize_t mika_write(struct file *file, const char __user *buffer, size_t count, loff_t *f_pos) {
    char *tmp = kzalloc((count+1), GFP_KERNEL);
    unsigned long val, val2 = 0;
    if(!tmp) return -ENOMEM;
    if(copy_from_user(tmp, buffer, count)){
        kfree(tmp);
        return EFAULT;
    }
    baka_name = tmp;
    if (memcmp(baka_name, "listvma", 7) == 0) list_vma();
    else if (memcmp(baka_name, "findpage", 8) == 0) {
        if (sscanf(baka_name + 8, "%lx", &val) == 1) {
            find_page(val);
        }
    } else if (memcmp(baka_name, "writeval", 8) == 0) {
        if (sscanf(baka_name + 8, "%lx %lx", &val, &val2) == 2) {
            mika_write_val(val, val2);
            printk("test here?");
        }
    }
    return count;
}

static int mika_open(struct inode *inode, struct file *file) {
    return single_open(file, mika_proc_show, NULL);
}

static const struct file_operations mika_fops = {
    .owner= THIS_MODULE,
    .open= mika_open,
    .read= seq_read,
    .write  = mika_write,
    .llseek= seq_lseek,
     .release= single_release
};

static int __init  hello_init(void){
    int i = 0;
    printk(KERN_INFO "Connichiwa~ Baka No.%d\n Eto your name is %s!\n", baka_num, namae);
    // test_dir = proc_mkdir("Mika_chigen", NULL);
    test_file = proc_create("mtest", S_IFREG|S_IRUGO|S_IWUSR, NULL, &mika_fops);
    if (!test_file) {
        printk(KERN_ERR "unable to create /proc/mtest\n");
        return -EIO;
    }
    list_vma();
    return 0;
}

static void __exit  hello_exit(void){
    printk(KERN_INFO "Urusai na! %s is BAKA No.%d!\n", namae, baka_num);
    remove_proc_entry("mtest", NULL);
}

module_init(hello_init);
module_exit(hello_exit);

