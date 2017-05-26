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

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x8d92db7f, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xb344fb9e, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x7b1f1399, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x77033d37, __VMLINUX_SYMBOL_STR(generic_file_llseek) },
	{ 0x60a13e90, __VMLINUX_SYMBOL_STR(rcu_barrier) },
	{ 0x60a6615a, __VMLINUX_SYMBOL_STR(mount_bdev) },
	{ 0xcf289c1e, __VMLINUX_SYMBOL_STR(d_add) },
	{ 0xf963c995, __VMLINUX_SYMBOL_STR(page_symlink_inode_operations) },
	{ 0x4a214627, __VMLINUX_SYMBOL_STR(generic_read_dir) },
	{ 0x97651e6c, __VMLINUX_SYMBOL_STR(vmemmap_base) },
	{ 0x59890325, __VMLINUX_SYMBOL_STR(__bread_gfp) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x8bf56296, __VMLINUX_SYMBOL_STR(kmem_cache_free) },
	{ 0xa33d870d, __VMLINUX_SYMBOL_STR(set_nlink) },
	{ 0xa07a37f0, __VMLINUX_SYMBOL_STR(memchr) },
	{ 0xbea0b184, __VMLINUX_SYMBOL_STR(generic_ro_fops) },
	{ 0xe691130b, __VMLINUX_SYMBOL_STR(unlock_page) },
	{ 0x52118a81, __VMLINUX_SYMBOL_STR(inode_nohighmem) },
	{ 0xa28a2090, __VMLINUX_SYMBOL_STR(__brelse) },
	{ 0xe304a181, __VMLINUX_SYMBOL_STR(inode_init_once) },
	{ 0x7cd8d75e, __VMLINUX_SYMBOL_STR(page_offset_base) },
	{ 0x1b68a7e0, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0xa916b694, __VMLINUX_SYMBOL_STR(strnlen) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x36364fc1, __VMLINUX_SYMBOL_STR(unlock_new_inode) },
	{ 0x9d6068fa, __VMLINUX_SYMBOL_STR(kill_block_super) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x8d543481, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xa907f80c, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0x9881a0, __VMLINUX_SYMBOL_STR(register_filesystem) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x643e0ce5, __VMLINUX_SYMBOL_STR(call_rcu_sched) },
	{ 0xd81c1923, __VMLINUX_SYMBOL_STR(sync_filesystem) },
	{ 0xd79aa3d4, __VMLINUX_SYMBOL_STR(sb_set_blocksize) },
	{ 0x42aa8dd4, __VMLINUX_SYMBOL_STR(d_make_root) },
	{ 0xec8e92ef, __VMLINUX_SYMBOL_STR(unregister_filesystem) },
	{ 0x1a34cfc8, __VMLINUX_SYMBOL_STR(init_special_inode) },
	{ 0x7f7057c6, __VMLINUX_SYMBOL_STR(iget_locked) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "DE8A189A4257A7118D1263D");
