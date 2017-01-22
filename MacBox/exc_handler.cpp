//
//  exc_handler.cpp
//  MacBox
//
//  Created by Shogun3D on 1/21/17.
//  Copyright © 2017 Shogun3D. All rights reserved.
//

#include "exc_handler.hpp"
#include <iostream>

#define _XOPEN_SOURCE

#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <unistd.h>
#include <assert.h>

#include <sys/mman.h>



void macbox_exception_handler( int sig_num, siginfo_t* siginfo, void* context )
{
    void* array[50];
    void* caller_address;
    char** messages;
    int size, i;
    ucontext_t* uc = (ucontext_t*) context;
    
#ifdef __i386__
    /* Get the address of where this signal was raised */
    caller_address = (void*) uc->uc_mcontext->__ss.__eip;
#else
#error MacBox is only compatible with i386 arch (x86-32)!
#endif
    
    /* Print out the exception details */
    std::cerr << "Signal " << sig_num << " (" << strsignal(sig_num) << ") address is " << siginfo->si_addr
        << " from " << caller_address << std::endl;
    
    /* Get our backtrace */
    /* TODO: Will we ever need more than 50? */
    size = backtrace( array, 50 );
    
    /* Overwrite sigaction with the caller's address */
    array[1] = caller_address;
    
    /* Now, get the complete list of backtrace symbols */
    messages = backtrace_symbols( array, size );
    
    /* Print out the entire stack, except the first one, as it just points here. */
    for( i = 1; i < size && messages != NULL; ++i )
    {
        std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
    }
    
    free( messages );
    
    exit( EXIT_FAILURE );
}

/* Setup our exception handler */
bool macbox_init_exception_handler()
{
    struct sigaction sigact;
    
    sigact.sa_sigaction = macbox_exception_handler;
    sigact.sa_flags = SA_RESTART | SA_SIGINFO;
    
    /* Catch segfaults, traps and illegal instructions */
    assert( !sigaction( SIGSEGV, &sigact, (struct sigaction*) NULL ) );
    assert( !sigaction( SIGTRAP, &sigact, (struct sigaction*) NULL ) );
    assert( !sigaction( SIGILL,  &sigact, (struct sigaction*) NULL ) );
    
    /*int ret = sigaction( SIGSEGV, &sigact, (struct sigaction*) NULL );
     if( ret != 0 )
     {
     std::cerr << __PRETTY_FUNCTION__ << "Error setting signal handler! (" << strsignal( SIGSEGV ) << ")" << std::endl;
     return false;
     }*/
    
    return true;
}
