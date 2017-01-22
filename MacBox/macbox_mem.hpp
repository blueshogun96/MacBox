//
//  macbox_mem.hpp
//  MacBox
//
//  Created by Shogun3D on 1/21/17.
//  Copyright © 2017 Shogun3D. All rights reserved.
//

#ifndef macbox_mem_hpp
#define macbox_mem_hpp

/* Reserves the 64mb address space starting at 0x10000 */
bool macbox_map_address();

/* Returns control of this memory range back to the OS */
void macbox_unmap_address();

#endif /* macbox_mem_hpp */
