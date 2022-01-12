/* ------------------------------------------------------------------------- */
/*                                                                           */
/* Dummy char driver                                                         */
/*                                                                           */
/* Copyright (C) 2017, Chris Simmonds (chris@2net.co.uk)                     */
/*                                                                           */
/* This program is free software; you can redistribute it and/or modify      */
/* it under the terms of the GNU General Public License as published by      */
/* the Free Software Foundation; either version 2 of the License, or         */
/* (at your option) any later version.                                       */
/*                                                                           */
/* This program is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU          */
/* General Public License for more details.                                  */
/*                                                                           */
/* You should have received a copy of the GNU General Public License         */
/* along with this program; if not, write to the Free Software               */
/* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA   */
/*                                                                           */
/* ------------------------------------------------------------------------- */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/device.h>

#define CREATE_CLASS 1

#define DEVICE_NAME "dummy"
// You can assign your own major number: 0 means assigned by kernel. 
#define MAJOR_NUM 0
#define NUM_DEVICES 4

#if CREATE_CLASS
static struct class *dummy_class;
#endif

static int major_num = 0;

static int dummy_open(struct inode *inode, struct file *file)
{
    pr_info("%s\n", __func__);
    return 0;
}

static int dummy_release(struct inode *inode, struct file *file)
{
    pr_info("%s\n", __func__);
    return 0;
}

static ssize_t dummy_read(struct file *file, char *buffer, size_t length, loff_t * offset)
{
    pr_info("%s %lu\n", __func__, length);
    return 0;
}

static ssize_t dummy_write(struct file *file, const char *buffer, size_t length, loff_t * offset)
{
    pr_info("%s %lu\n", __func__, length);
    return length;
}

struct file_operations dummy_fops = {
    .owner = THIS_MODULE,
    .open = dummy_open,
    .release = dummy_release,
    .read = dummy_read,
    .write = dummy_write,
};

int __init dummy_init(void)
{
#if CREATE_CLASS
    int i;
#endif

    // If you want to generate major number automatically, MAJOR_NUM can be 0 and return value is major number
    major_num = register_chrdev(MAJOR_NUM, DEVICE_NAME, &dummy_fops);
    if (major_num < 0)
        return major_num;
    printk("Dummy loaded: major number=%d\n", major_num);

#if CREATE_CLASS
    dummy_class = class_create(THIS_MODULE, DEVICE_NAME);
    for (i = 0; i < NUM_DEVICES; i++) {
        device_create(dummy_class, NULL, MKDEV(MAJOR_NUM, i), NULL, "dummy%d", i);
    }
#endif

    return 0;
}

void __exit dummy_exit(void)
{
#if CREATE_CLASS
    int i;
    for (i = 0; i < NUM_DEVICES; i++) {
        device_destroy(dummy_class, MKDEV(MAJOR_NUM, i));
    }
    class_destroy(dummy_class);
#endif

    unregister_chrdev(MAJOR_NUM, DEVICE_NAME);
    printk("Dummy unloaded\n");
}

module_init(dummy_init);
module_exit(dummy_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Chris Simmonds");
MODULE_DESCRIPTION("A dummy driver");
