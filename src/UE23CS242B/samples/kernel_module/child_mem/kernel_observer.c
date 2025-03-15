#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nathan");
MODULE_DESCRIPTION("Kernel module observing user-space processes");
MODULE_VERSION("1.0");

static pid_t parent_pid = -1; // Parent PID to observe
ssize_t observer_write(struct file *file, const char __user *buffer, size_t count, loff_t *pos);
module_param(parent_pid, int, 0444);
MODULE_PARM_DESC(parent_pid, "User-space Parent PID to track");

static struct task_struct *observer_thread;

// Helper: Print memory info of a process
static void print_memory_info(struct task_struct *task) {
    struct mm_struct *mm = task->mm;
    if (!mm) return; // No memory info available

    printk(KERN_INFO "   |--Child PID: %d (PPID: %d)\n", task->pid, task->real_parent->pid);
    printk(KERN_INFO "      |--Memory Start: 0x%lx, End: 0x%lx\n", mm->start_brk, mm->brk);
}

// Observer thread function
static int observer_fn(void *data) {
    while (!kthread_should_stop()) {
        struct task_struct *task;

        for_each_process(task) {
            if (task->real_parent->pid == parent_pid) {
                print_memory_info(task);
            }
        }

        msleep(1000); // Scan every second
    }
    return 0;
}

// Module initialization
static int __init observer_init(void) {
    if (parent_pid == -1) {
        printk(KERN_ERR "Error: Please provide a parent_pid parameter.\n");
        return -EINVAL;
    }

    printk(KERN_INFO "Observing children of Parent PID: %d\n", parent_pid);

    observer_thread = kthread_run(observer_fn, NULL, "observer_thread");
    if (IS_ERR(observer_thread)) {
        printk(KERN_ERR "Failed to create observer thread\n");
        return PTR_ERR(observer_thread);
    }

    return 0;
}

// Module cleanup
static void __exit observer_exit(void) {
    if (observer_thread) {
        kthread_stop(observer_thread);
        printk(KERN_INFO "Observer thread stopped.\n");
    }
    printk(KERN_INFO "Exiting kernel observer module.\n");
}

module_init(observer_init);
module_exit(observer_exit);
