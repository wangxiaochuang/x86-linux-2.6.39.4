/*
 * The "user cache".
 *
 * (C) Copyright 1991-2000 Linus Torvalds
 *
 * We have a per-user structure to keep track of how many
 * processes, files etc the user has claimed, in order to be
 * able to have per-user limits for system resources. 
 */

#include <linux/init.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/bitops.h>
#include <linux/key.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/user_namespace.h>

/*
 * userns count is 1 for root user, 1 for init_uts_ns,
 * and 1 for... ?
 */
struct user_namespace init_user_ns = {
	.kref = {
		.refcount	= ATOMIC_INIT(3),
	},
	.creator = &root_user,
};
EXPORT_SYMBOL_GPL(init_user_ns);

struct user_struct root_user = {
    .__count    = ATOMIC_INIT(2),
    .processes  = ATOMIC_INIT(1),
    .files      = ATOMIC_INIT(0),
    .sigpending = ATOMIC_INIT(0),
    .locked_shm     = 0,
    .user_ns    = &init_user_ns,
};
