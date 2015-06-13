#include <linux/module.h>
#include <linux/fs.h>

static struct file_system_type pext_fs_type = {
	.owner = THIS_MODULE,
	.name = "pext",
	.fs_flags = FS_REQUIRES_DEV,
};

static int __init init_pext_fs(void)
{
	int ret;

	ret = register_filesystem(&pext_fs_type);

	if (!ret)
		printk(KERN_INFO"pext file system is registered\n");

	return ret;
}

static void __exit exit_pext_fs(void)
{
	int ret;

	ret = unregister_filesystem(&pext_fs_type);

	if (!ret)
		printk(KERN_INFO"pext file system is unregistered\n");
}

MODULE_AUTHOR("Seunghun Lee");
MODULE_DESCRIPTION("Pratice for Extended Filesystem");
MODULE_LICENSE("GPL");
module_init(init_pext_fs)
module_exit(exit_pext_fs)
