//
//  blockI.h
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#ifndef __A5__blockI__
#define __A5__blockI__

#include <iostream>
#include "block.h"

class blockI:public block{
  int dir; //used to decide how to rotate
public:
    blockI(int level);
    //two rotate function that change part
    void rotateClock();
    void rotateCClock();
};

#endif /* defined(__A5__blockI__) */
