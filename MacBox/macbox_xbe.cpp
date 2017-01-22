//
//  macbox_xbe.cpp
//  MacBox
//
//  Created by Shogun3D on 1/21/17.
//  Copyright © 2017 Shogun3D. All rights reserved.
//

#include "macbox_typedefs.hpp"
#include "macbox_xbe.hpp"
#include "macbox_d3d.hpp"
#include "macbox_d3ddevice.hpp"

#include <pthread.h>


void macbox_vm_callback( void* main_function )
{
    /* Give this thread a proper name */
    pthread_setname_np( "VMThread" );
    
    /* Jump to the main function (not the entry point) */
    void(*_main)(void) = (void(*)(void)) main_function;
    _main();
    
    pthread_exit(NULL);
}

void macbox_install_wrapper( void* function_addr, void* wrapper_addr )
{
    uint8_t* func = (uint8_t*) function_addr;
    
    *(uint8_t*) &func[0] = 0xE9;    // JMP rel32 (quick and easy)
    *(uint32_t*)&func[1] = (uint32_t) wrapper_addr - (uint32_t) function_addr;
}

/* Opens a .xbe file and starts us at our main function */
bool macbox_xbe_run( const char* xbefile, uint32_t main_function )
{
    /* Open the .xbe file as binary */
    FILE* fp = fopen( xbefile, "rb" );
    if(fp)
    {
        /* Read in the contents and write it to our reserved memory address */
        fseek( fp, 0, SEEK_END );
        size_t size = ftell(fp);
        fseek( fp, 0, SEEK_SET );
        fread( reinterpret_cast<void*>(0x10000), size, 1, fp );
        fclose(fp);
        
        /* TODO: Move this elsewhere and don't hard code it either */
        macbox_install_wrapper( reinterpret_cast<void*>(0x195B0), reinterpret_cast<void*>(Direct3D_CreateDevice) );
        macbox_install_wrapper( reinterpret_cast<void*>(0x1A270), reinterpret_cast<void*>(D3DDevice_Clear) );
        macbox_install_wrapper( reinterpret_cast<void*>(0x1ABC0), reinterpret_cast<void*>(D3DDevice_Swap) );
        
        /* Start up the .xbe in a new thread */
        pthread_t thread;
        pthread_create( &thread, NULL, (void *(*)(void*)) macbox_vm_callback, (void*) main_function );
        pthread_join( thread, NULL );
    }
    
    return false;
}
