//
//  main.cpp
//  MacBox
//
//  Created by Shogun3D on 1/21/17.
//  Copyright © 2017 Shogun3D. All rights reserved.
//

#include "exc_handler.hpp"
#include "macbox_mem.hpp"
#include "macbox_xbe.hpp"


/* First things first, don't run this in any other mode than 32-bit */
#ifndef __i386__
#error MacBox is only compatible with i386 arch (x86-32)!
#endif


int main( int argc, char** argv )
{
    /* Setup exception handler */
    macbox_init_exception_handler();
    
    /* Test run an xbe */
    macbox_map_address();
    macbox_xbe_run( "/Users/shogun3d/Documents/MacBox/samples/Tut01_CreateDevice/Release/CreateDevice.xbe", 0x11190 );
    macbox_unmap_address();
    
    return 0;
}
