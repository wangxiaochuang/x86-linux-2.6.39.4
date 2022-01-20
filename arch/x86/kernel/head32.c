#include <linux/init.h>
#include <linux/start_kernel.h>
#include <linux/mm.h>
#include <linux/memblock.h>

#include <asm/setup.h>
#include <asm/sections.h>
#include <asm/e820.h>
#include <asm/page.h>
#include <asm/trampoline.h>
#include <asm/apic.h>
#include <asm/io_apic.h>
#include <asm/bios_ebda.h>
#include <asm/tlbflush.h>

void __init i386_start_kernel(void) {}
