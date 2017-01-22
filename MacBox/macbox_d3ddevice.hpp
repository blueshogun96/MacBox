//
//  macbox_d3ddevice.hpp
//  MacBox
//
//  Created by Shogun3D on 1/21/17.
//  Copyright © 2017 Shogun3D. All rights reserved.
//

#ifndef macbox_d3ddevice_hpp
#define macbox_d3ddevice_hpp

#include <stdio.h>

/*
 * Fake D3DDevice
 */
struct D3DDevice
{
    uint32_t unused;    /* Temporary */
};


/*
 * Fake D3DDevice functions
 */
HRESULT CALLBACK D3DDevice_Clear( DWORD Count, const void* pRects, DWORD Flags, DWORD Colour, float Z, DWORD Stencil );
HRESULT CALLBACK D3DDevice_Swap( DWORD Flags );

#endif /* macbox_d3ddevice_hpp */
