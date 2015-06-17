#include <linux/module.h>
#include <linux/fs.h>

void pext_msg(struct super_block *sb, const char *prefix,
		const char *fmt, ...)
{
	struct va_format vaf;
	va_list args;

	va_start(args, fmt);

	vaf.fmt = fmt;
	vaf.va = &args;

	printk("%sPEXT-fs (%s): %pV\n", prefix, sb->s_id, &vaf);

	va_end(args);
}

static int pext_fill_super(struct super_block *sb, void *data, int silent)
{
	return -1;
}

static struct dentry *pext_mount(struct file_system_type *fs_type,
		int flags, const char *dev_name, void *data)
{
	return mount_bdev(fs_type, flags, dev_name, data, pext_fill_super);
}

static struct file_system_type pext_fs_type = {
	.owner = THIS_MODULE,
	.name = "pext",
	.mount = pext_mount,
	.kill_sb = kill_block_super,
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
