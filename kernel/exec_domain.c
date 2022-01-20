/*
 * Handling of different ABIs (personalities).
 *
 * We group personalities into execution domains which have their
 * own handlers for kernel entry points, signal mapping, etc...
 *
 * 2001-05-06	Complete rewrite,  Christoph Hellwig (hch@infradead.org)
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/kmod.h>
#include <linux/module.h>
#include <linux/personality.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/seq_file.h>
#include <linux/syscalls.h>
#include <linux/sysctl.h>
#include <linux/types.h>
#include <linux/fs_struct.h>


static struct exec_domain *exec_domains = &default_exec_domain;
static DEFINE_RWLOCK(exec_domains_lock);


static unsigned long ident_map[32] = {
	0,	1,	2,	3,	4,	5,	6,	7,
	8,	9,	10,	11,	12,	13,	14,	15,
	16,	17,	18,	19,	20,	21,	22,	23,
	24,	25,	26,	27,	28,	29,	30,	31
};

struct exec_domain default_exec_domain = {
	.name		= "Linux",		/* name */
	.pers_low	= 0, 			/* PER_LINUX personality. */
	.pers_high	= 0,			/* PER_LINUX personality. */
	.signal_map	= ident_map,		/* Identity map signals. */
	.signal_invmap	= ident_map,		/*  - both ways. */
};


