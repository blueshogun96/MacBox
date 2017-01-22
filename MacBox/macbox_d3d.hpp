//
//  macbox_d3d.hpp
//  MacBox
//
//  Created by Shogun3D on 1/21/17.
//  Copyright © 2017 Shogun3D. All rights reserved.
//

#ifndef macbox_d3d_hpp
#define macbox_d3d_hpp

#include <stdio.h>
#include <stdint.h>

#include <SDL2/SDL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>


/*
 * Fake D3D macros
 */

#define D3D_OK  0


/*
 * Fake D3D types
 */

struct D3DPRESENT_PARAMETERS
{
    DWORD    BackBufferWidth;
    DWORD    BackBufferHeight;
    DWORD    BackBufferFormat;
    DWORD    BackBufferCount;
    DWORD    MultiSampleType;
    DWORD    SwapEffect;
    void*    hDeviceWindow;
    int      Windowed;
    int      EnableAutoDepthStencil;
    DWORD    AutoDepthStencilFormat;
    DWORD    Flags;
    DWORD    FullScreen_RefreshRateInHz;
    DWORD    FullScreen_PresentationInterval;
    void*    BufferSurfaces[3];
    void*    DepthStencilSurface;
};

/*
 * Fake D3D interfaces
 */
struct D3DDevice;

#include "macbox_d3ddevice.hpp"


/*
 * Fake D3D functions
 */
HRESULT CALLBACK Direct3D_CreateDevice( DWORD Adapter, int DeviceType, void* hFocusWindow, DWORD BehaviourFlags,
                               D3DPRESENT_PARAMETERS* pPresentationParameters, D3DDevice** ppReturnedDeviceInterface );

#endif /* macbox_d3d_hpp */
