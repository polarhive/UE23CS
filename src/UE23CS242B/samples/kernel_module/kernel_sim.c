#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/sched/signal.h>

#define NUM_CHILDREN 3

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nathan");
MODULE_DESCRIPTION("Kernel module simulating user-space logging");
MODULE_VERSION("1.0");

static struct task_struct *child_threads[NUM_CHILDREN];

// Function executed by each "child" thread
static int child_fn(void *data) {
    int id = *(int *)data;
    printk(KERN_INFO "   |--Kernel Child %d (PID: %d)\n", id, current->pid);

    // Simulating dynamic memory allocation
    int *dmem = kmalloc(10 * sizeof(int), GFP_KERNEL);
    if (!dmem) {
        printk(KERN_ERR "      |--Memory allocation failed for child %d\n", id);
        return -ENOMEM;
    }
    printk(KERN_INFO "      |--Child %d allocated memory at: %p\n", id, dmem);
    
    // Simulate work (5 seconds)
    msleep(5000);  

    kfree(dmem);
    printk(KERN_INFO "      |--Child %d exiting\n", id);
    return 0;
}

// Initialization function (module entry point)
static int __init kernel_sim_init(void) {
    int i;
    printk(KERN_INFO "Parent (Kernel Thread) PID: %d\n", current->pid);

    for (i = 0; i < NUM_CHILDREN; i++) {
        int *child_id = kmalloc(sizeof(int), GFP_KERNEL);
        if (!child_id) {
            printk(KERN_ERR "Failed to allocate memory for child ID\n");
            return -ENOMEM;
        }
        *child_id = i;

        child_threads[i] = kthread_run(child_fn, child_id, "child_thread_%d", i);
        if (IS_ERR(child_threads[i])) {
            printk(KERN_ERR "Failed to create child thread %d\n", i);
            kfree(child_id);
            return PTR_ERR(child_threads[i]);
        }
    }

    return 0;
}

// Cleanup function (module exit point)
static void __exit kernel_sim_exit(void) {
    int i;
    for (i = 0; i < NUM_CHILDREN; i++) {
        if (child_threads[i]) {
            kthread_stop(child_threads[i]);
            printk(KERN_INFO "Stopped child thread %d\n", i);
        }
    }
    printk(KERN_INFO "Goodbye from kernel module!\n");
}

module_init(kernel_sim_init);
module_exit(kernel_sim_exit);
