#include <linux/kernel.h>

asmlinkage long sys_readAddr(void *p)
{
  printk("Hello world\n");
  return 0;
}
