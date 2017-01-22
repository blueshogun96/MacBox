//
//  macbox_d3ddevice.cpp
//  MacBox
//
//  Created by Shogun3D on 1/21/17.
//  Copyright © 2017 Shogun3D. All rights reserved.
//

#include "macbox_typedefs.hpp"
#include "macbox_d3d.hpp"
#include "macbox_d3ddevice.hpp"


HRESULT CALLBACK D3DDevice_Clear( DWORD Count, const void* pRects, DWORD Flags, DWORD Colour, float Z, DWORD Stencil )
{
    printf( "D3DDevice_Clear()\n\n" );
    
    return S_OK;
}

HRESULT CALLBACK D3DDevice_Swap( DWORD Flags )
{
    printf( "D3DDevice_Swap()\n\n" );
    return S_OK;
}
