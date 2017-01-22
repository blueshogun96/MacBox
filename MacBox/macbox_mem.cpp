//
//  macbox_mem.cpp
//  MacBox
//
//  Created by Shogun3D on 1/21/17.
//  Copyright © 2017 Shogun3D. All rights reserved.
//

#include "macbox_mem.hpp"
#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>


/*
 * NOTES: In order for the code below to work on macOS, the following needs to be added to "other linker flags" in XCode:
 *
 *        -pagezero_size 0x10000000 -segprot __PAGEZERO rwx rwx
 *
 *        I don't know exactly what this does, but this was what I had to add in order for the code to stop crashing
 *        soon after the memory address was setup.
 */

void* ram = NULL;

/* Reserves the 64mb address space starting at 0x10000 */
bool macbox_map_address()
{
    ram = mmap( reinterpret_cast<void*>(0x10000),       /* This is the base address we need */
               1 << 20,                                 /* 64mb of the address space onward */
               PROT_EXEC | PROT_READ | PROT_WRITE,      /* We need read, write and most importantly, executable access */
               MAP_ANONYMOUS | MAP_PRIVATE | MAP_FIXED, /* Keep this memory range to ourselves, and this is a fixed address */
                                                        /* And for crying out loud, without MAP_FIXED the whole concept is out the window! */
               0, 0 );
    if( !ram )
        return false;
    
    return true;
}

/* Returns control of this memory range back to the OS */
void macbox_unmap_address()
{
    munmap( ram, 1 << 20 );
}

