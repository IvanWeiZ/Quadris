//
//  blockL.h
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#ifndef __A5__blockL__
#define __A5__blockL__

#include <iostream>
#include "block.h"
class blockL:public block{
  int dir;  //used to find a way to rotate
public:
    blockL(int level);
    void rotateClock();
    void rotateCClock();
};


#endif /* defined(__A5__blockL__) */
