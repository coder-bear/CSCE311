/**
 * Linux device driver to get the current working directory
 *
 * Inspired by Valerie Henson's
 *   `/dev/hello_world: A Simple Introduction to Device Drivers under Linux'
 *   at https://cse.sc.edu/~zeng1/csce311-f18/files/valerie-henson-device-drivers-hello.pdf
 * Inspired by user eniac
 *   `Linux: Creating an entry in /proc file system (Part 1: The hello_proc pseudo file)'
 *   at http://pointer-overloading.blogspot.com/2013/09/linux-creating-entry-in-proc-file.html
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>  // proc_create, remove_proc_entry
#include <linux/seq_file.h>  // single_open, single_release, seq_printf, seq_read, seq_lseek
#include <linux/slab.h>  // kmalloc, kfree
#include <linux/sched.h>  // current
#include <linux/dcache.h>  // d_path
#include <linux/fs_struct.h>  // fs_struct, path, get_fs_pwd

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hunter Damron, Graham McDonald, Reed Segars");
MODULE_DESCRIPTION("Linux device driver to get the current working directory");
MODULE_VERSION("0.0.1");

#define PATH_MAX_LEN 4096

static int cwd_proc_show(struct seq_file *m, void *v) {
  struct path cwd;
  char *path_str, *path_str_ptr;
  get_fs_pwd(current->fs, &cwd);  // Gets cwd in a thread safe way
  path_str = kmalloc(PATH_MAX_LEN, GFP_USER);  // Creates string which will contain cwd
  path_str_ptr = d_path(&cwd, path_str, PATH_MAX_LEN);  // Reads cwd into path_str
  kfree(path_str);  // Frees path_str
  path_put(&cwd);  // Returns cwd to system
  seq_printf(m, "%s\n", path_str_ptr);  // Prints the gotten cwd
  return 0;
}

static int cwd_proc_open(struct inode *inode, struct file *fp) {
  return single_open(fp, cwd_proc_show, NULL);  // Signals that read should call cwd_proc_show
}

static const struct file_operations proc_options = {
  owner: THIS_MODULE,
  open: cwd_proc_open,
  read: seq_read,
  llseek: seq_lseek,
  release: single_release
};

static int __init cwd_driver_init(void) {
  proc_create("cwd", 0, NULL, &proc_options);  // Creates entry at /proc/cwd
  return 0;
}

static void __exit cwd_driver_exit(void) {
  remove_proc_entry("cwd", NULL);  // Removes entry at /proc/cwd
}

module_init(cwd_driver_init);
module_exit(cwd_driver_exit);
