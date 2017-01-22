//
//  macbox_typedefs.hpp
//  MacBox
//
//  Created by Shogun3D on 1/21/17.
//  Copyright © 2017 Shogun3D. All rights reserved.
//

#ifndef macbox_typedefs_h
#define macbox_typedefs_h

#include <stdint.h>

/*
 * Common macros
 */

#define S_OK    0
#define E_FAIL  0x80004005

#define CALLBACK __attribute__((__stdcall__)) __attribute__((__force_align_arg_pointer__)) __attribute__((aligned(4)))

/*
 * Common typedefs from Win32 and Xbox
 */

typedef unsigned long    DWORD;
typedef unsigned long    HRESULT;


#endif /* macbox_typedefs_h */
