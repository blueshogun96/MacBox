//
//  macbox_d3d.cpp
//  MacBox
//
//  Created by Shogun3D on 1/21/17.
//  Copyright © 2017 Shogun3D. All rights reserved.
//

#include "macbox_typedefs.hpp"
#include "macbox_d3d.hpp"
#include "macbox_d3ddevice.hpp"

#include <memory>

std::unique_ptr<D3DDevice*> D3D__pDevice( new D3DDevice* );


HRESULT CALLBACK Direct3D_CreateDevice( DWORD Adapter, int DeviceType, void* hFocusWindow, DWORD BehaviourFlags,
                              D3DPRESENT_PARAMETERS* pPresentationParameters, D3DDevice** ppReturnedDeviceInterface )
{
    printf( "Direct3D_CreateDevice()\n\n" );
    
    /* Gonna give it something, for now. */
    *ppReturnedDeviceInterface = *D3D__pDevice.get();
    
    return D3D_OK;
}
