#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/types.h>

#include <hello1.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("Lab5: hello1\n");
MODULE_AUTHOR("Gusakova IV-82\n");

EXPORT_SYMBOL(hello_func);

static int hello_func(uint n)
{
        int i;
        if (n < 0) {
                pr_err("Error (n<0)\n");
        }
        else if (n == 0) {
                pr_warn("Warning (n=0)\n");
        }
        else if (n >= 5 && n <= 10) {
                pr_warn("Warning (5<=n<=10)\n");
        }
        else if (n > 10) {
                pr_err("Error (n>10)\n");
                return -EINVAL;
        }
        for (i = 0; i < n; i++) {
                pr_info("Hello, world!!!\n");
        }
        return 0;
}

static int __init hello1_init(void)
{
        pr_info("hello1 init\n");
        return 0;
}

static void __exit hello1_exit(void)
{
        pr_info("hello1 exit\n");
}

module_init(hello1_init);
module_exit(hello1_exit);
