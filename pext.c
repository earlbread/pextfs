#include <linux/module.h>

static int __init init_pext_fs(void)
{
	printk(KERN_INFO"Hello pext fs\n");
	return 0;
}

static void __exit exit_pext_fs(void)
{
	printk(KERN_INFO"Bye pext fs\n");
}

MODULE_AUTHOR("Seunghun Lee");
MODULE_DESCRIPTION("Pratice for Extended Filesystem");
MODULE_LICENSE("GPL");
module_init(init_pext_fs)
module_exit(exit_pext_fs)
