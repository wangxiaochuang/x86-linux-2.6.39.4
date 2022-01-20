#include <linux/module.h>
#include <linux/cred.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <linux/key.h>
#include <linux/keyctl.h>
#include <linux/init_task.h>
#include <linux/security.h>
#include <linux/cn_proc.h>


struct cred init_cred = {
    .usage          = ATOMIC_INIT(4),
#ifdef CONFIG_DEBUG_CREDENTIALS
    .subscribers        = ATOMIC_INIT(2),
    .magic          = CRED_MAGIC,
#endif
    .securebits     = SECUREBITS_DEFAULT,
    .cap_inheritable    = CAP_INIT_INH_SET,
    .cap_permitted      = CAP_FULL_SET,
    .cap_effective      = CAP_INIT_EFF_SET,
    .cap_bset       = CAP_INIT_BSET,
    .user           = INIT_USER
};
