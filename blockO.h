//
//  blockO.h
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#ifndef __A5__blockO__
#define __A5__blockO__

#include <iostream>
#include "block.h"
class blockO:public block{
public:
    blockO(int level);
    void rotateClock();
    void rotateCClock();
};
#endif /* defined(__A5__blockO__) */
