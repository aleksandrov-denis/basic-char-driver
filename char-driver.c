#include <linux/init.h>
#include <linux/module.h>

/*Char driver support*/
#include <linux/fs.h>

int basic_open(struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Inside the %s function!\n", __FUNCTION__);
	return 0;
}
ssize_t basic_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset){
	printk(KERN_ALERT "Inside the %s function!\n", __FUNCTION__);
        return 0;
}
ssize_t basic_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset){
	printk(KERN_ALERT "Inside the %s function!\n", __FUNCTION__);
        return length;
}
int basic_close(struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Inside the %s function!\n", __FUNCTION__);
        return 0;
}

/*Holds file operations to be performed on this device*/
struct file_operations basic_file_operations = {
	.owner = THIS_MODULE,
	.open = basic_open,
	.read = basic_read,
	.write = basic_write,
	.release = basic_close,
};

MODULE_LICENSE("GPL");

static int basic_init(void) {
        printk(KERN_ALERT "Initializing character driver!\n");
        
	/*Register with the kernel and declare that we want to register
	a character driver*/
	
	int t = register_chrdev(80 /*major num*/,
	"Basic Char Driver" /*name of driver*/,
	&basic_file_operations /*file operations*/);
	if(t<0){
		printk(KERN_ALERT "Initialization failed!\n");
		return t;	
	}
	return 0;
}

static void basic_exit(void) {
        printk(KERN_ALERT "Exiting character driver!\n");

	/*Unregister the char driver*/
	unregister_chrdev(80, "Basic Char Driver");
}
module_init(basic_init);
module_exit(basic_exit);
