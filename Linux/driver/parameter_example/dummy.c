#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int my_param = 0;
module_param(my_param, int, 0);
MODULE_PARM_DESC(my_param, "Parameter from user space.");

static int __init dummy_init(void)
{
    printk(KERN_INFO "Hello World\n");
    printk(KERN_INFO "my_param is %d\n", my_param);
    return 0;
}

static void __exit dummy_exit(void)
{
    printk(KERN_INFO "Goodbye World\n");
}

module_init(dummy_init);
module_exit(dummy_exit);

MODULE_AUTHOR("evshary");
MODULE_DESCRIPTION("Dummy example");
MODULE_LICENSE("GPL");
