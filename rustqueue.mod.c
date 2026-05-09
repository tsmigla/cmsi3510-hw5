#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x0566c749, "generic_file_open" },
	{ 0x18f7e105, "rust_helper_krealloc_node_align" },
	{ 0x7a5bfe83, "rust_helper___mutex_init" },
	{ 0xca2eebaa, "_RNvNtCsj9bqJNU6tGA_6kernel5print11call_printk" },
	{ 0x4a050e3f, "_RNvXsg_NtCscIHVMyPnRZn_4core3fmtbNtB5_7Display3fmt" },
	{ 0x9aa6980d, "mutex_lock" },
	{ 0xbd9ca522, "rust_helper_mutex_assert_is_held" },
	{ 0x5239eb88, "_copy_from_iter" },
	{ 0x9aa6980d, "mutex_unlock" },
	{ 0x65f3b200, "_copy_to_iter" },
	{ 0xfbe7861b, "memmove" },
	{ 0x7559929c, "_RNvXso_NtCsj9bqJNU6tGA_6kernel3fmtjNtB5_7Display3fmt" },
	{ 0x27122c48, "misc_deregister" },
	{ 0xc29de31a, "misc_register" },
	{ 0xe9277052, "_RNvNtCsj9bqJNU6tGA_6kernel5error9to_result" },
	{ 0x9b3f403c, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xb52929e2,
	0x0566c749,
	0x18f7e105,
	0x7a5bfe83,
	0x4a00bccb,
	0xca2eebaa,
	0x4a050e3f,
	0x9aa6980d,
	0xbd9ca522,
	0x5239eb88,
	0x9aa6980d,
	0xd272d446,
	0xd272d446,
	0xd272d446,
	0x65f3b200,
	0xfbe7861b,
	0x7559929c,
	0x27122c48,
	0xc29de31a,
	0xe9277052,
	0x9b3f403c,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"_RNvNtCscIHVMyPnRZn_4core9panicking19assert_failed_inner\0"
	"generic_file_open\0"
	"rust_helper_krealloc_node_align\0"
	"rust_helper___mutex_init\0"
	"_RNvNtNtCsj9bqJNU6tGA_6kernel5print14format_strings4INFO\0"
	"_RNvNtCsj9bqJNU6tGA_6kernel5print11call_printk\0"
	"_RNvXsg_NtCscIHVMyPnRZn_4core3fmtbNtB5_7Display3fmt\0"
	"mutex_lock\0"
	"rust_helper_mutex_assert_is_held\0"
	"_copy_from_iter\0"
	"mutex_unlock\0"
	"_RNvNtNtCscIHVMyPnRZn_4core9panicking11panic_const24panic_const_sub_overflow\0"
	"_RNvNtNtCscIHVMyPnRZn_4core9panicking11panic_const24panic_const_add_overflow\0"
	"_RNvNtNtCscIHVMyPnRZn_4core9panicking11panic_const24panic_const_mul_overflow\0"
	"_copy_to_iter\0"
	"memmove\0"
	"_RNvXso_NtCsj9bqJNU6tGA_6kernel3fmtjNtB5_7Display3fmt\0"
	"misc_deregister\0"
	"misc_register\0"
	"_RNvNtCsj9bqJNU6tGA_6kernel5error9to_result\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D1971EBBD63437D310DD464");
