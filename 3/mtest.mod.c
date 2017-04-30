#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x8d92db7f, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x89f86fe9, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x4c5003bf, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0xf40b1cb8, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0x892cd895, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x197084e, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0xc21fe945, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0xc6cdcd54, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0xe02598f6, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0xee112604, __VMLINUX_SYMBOL_STR(__put_page) },
	{ 0xdd430c88, __VMLINUX_SYMBOL_STR(put_zone_device_page) },
	{ 0xe7fe9499, __VMLINUX_SYMBOL_STR(find_vma) },
	{ 0x20c55ae0, __VMLINUX_SYMBOL_STR(sscanf) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x88db9f48, __VMLINUX_SYMBOL_STR(__check_object_size) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x166273e0, __VMLINUX_SYMBOL_STR(get_zone_device_page) },
	{ 0xce31b8a1, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x97651e6c, __VMLINUX_SYMBOL_STR(vmemmap_base) },
	{ 0x7cd8d75e, __VMLINUX_SYMBOL_STR(page_offset_base) },
	{ 0x9b4c95dd, __VMLINUX_SYMBOL_STR(pv_mmu_ops) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x72817129, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0xbe598f53, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xc063b9fb, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x52bd9fed, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xfa2fbb8c, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "1F72DD37E56896DBB9E1FA5");
