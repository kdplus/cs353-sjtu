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
	{ 0x84b303c1, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x51d7efed, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xe5981209, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x2c249cbc, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0x3673e836, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x8fec25d4, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x8d6578b2, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0x8f54a06b, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0x9015de1f, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x996d52bf, __VMLINUX_SYMBOL_STR(proc_mkdir) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x88db9f48, __VMLINUX_SYMBOL_STR(__check_object_size) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x408cdca5, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xb1bb7869, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "17AEACCD87240417C972B15");
