//
//  blockZ.h
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#ifndef __A5__blockZ__
#define __A5__blockZ__

#include <iostream>
#include "block.h"
class blockZ:public block{
   int dir; //used to decide which way to rotate
public:
    blockZ(int level);
    void rotateClock();
    void rotateCClock();
};


#endif /* defined(__A5__blockZ__) */
