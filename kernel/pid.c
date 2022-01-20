#include <linux/mm.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/rculist.h>
#include <linux/bootmem.h>
#include <linux/hash.h>
#include <linux/pid_namespace.h>
#include <linux/init_task.h>
#include <linux/syscalls.h>

#define pid_hashfn(nr, ns)  \
	    hash_long((unsigned long)nr + (unsigned long)ns, pidhash_shift)
static struct hlist_head *pid_hash;
static unsigned int pidhash_shift = 4;
struct pid init_struct_pid = INIT_STRUCT_PID;

struct pid_namespace init_pid_ns = {
    .kref = {
        .refcount       = ATOMIC_INIT(2),
    },
    .last_pid = 0,
    .level = 0,
    .child_reaper = &init_task,
};
EXPORT_SYMBOL_GPL(init_pid_ns);
