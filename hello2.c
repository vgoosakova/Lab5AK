#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>

#include <hello1.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("Lab5: hello2\n");
MODULE_AUTHOR("Gusakova IV-82\n");

static uint n = 1;
module_param(n, uint, 0);
MODULE_PARM_DESC(n, "How many hello want to print?\n");

static int hello_init(void)
{
        return hello_func(n);
}

static void hello_exit(void)
{
        printk(KERN_ALERT "hello2 exit\n");
}

module_init(hello_init);
module_exit(hello_exit);
