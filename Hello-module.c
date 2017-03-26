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
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Mika");
static int baka_num;
module_param(baka_num, int, 0644);

// static int(*oldcall)(void);
struct proc_dir_entry *test_dir, *test_file;

char *baka_name = "Tadano Baka\0";
static int mika_proc_show(struct seq_file *m, void *v) {
    seq_printf(m, "%s\n", baka_name);
    return 0;
}
/*
static ssize_t mika_write(struct file *file, const char __user *buffer, size_t count, loff_t *pos) {
    char write_buffer[1024];
    if (count > 0) {
        //if (get_user(write_buffer, buffer)) return -EFAULT;
        strcpy(baka_name, write_buffer);
    }
    return count;
}
*/

static ssize_t mika_write(struct file *file, const char __user *buffer, size_t count, loff_t *f_pos) {
    char *tmp = kzalloc((count+1), GFP_KERNEL);
    if(!tmp) return -ENOMEM;
    if(copy_from_user(tmp, buffer, count)){
        kfree(tmp);
        return EFAULT;
    }
    kfree(baka_name);
    baka_name = tmp;
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
    printk(KERN_INFO "Connichiwa~ Baka No.%d Mihoyo desu~!\n", baka_num);

    struct proc_dir_entry *entry = NULL;
    test_dir = proc_mkdir("Mika_chigen", NULL);
    test_file = proc_create("Connichiwa", S_IFREG|S_IRUGO|S_IWUSR, test_dir, &mika_fops);
    if (!test_file) {
        printk(KERN_ERR "unable to create /proc/Mika_chigen/Connichiwa\n");
        return -EIO;
    }
    return 0;
}

static void __exit  hello_exit(void){
    printk(KERN_INFO "Urusai na! BAKA No.%d!\n", baka_num);
    remove_proc_entry("Connichiwa", test_dir);
    remove_proc_entry("Mika_chigen", NULL);
}

module_init(hello_init);
module_exit(hello_exit);

