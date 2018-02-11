//
//  blockJ.h
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#ifndef __A5__blockJ__
#define __A5__blockJ__

#include <iostream>
#include "block.h"
class blockJ:public block{
  int dir;//used to dectect how to rotate
public:
    blockJ(int level);
    void rotateClock();
    void rotateCClock();
};

#endif /* defined(__A5__blockJ__) */
