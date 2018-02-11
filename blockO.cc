//
//  blockO.cc
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#include "blockO.h"

blockO::blockO(int level){
    this->level=level;
    this->cellAlive=4;
    this->type='O';
    vector *v= new vector[4];
    v[0]=vector(3,0);
    v[1]=vector(3,1);
    v[2]=vector(4,0);
    v[3]=vector(4,1);
    this->parts=v;
}

void blockO::rotateClock(){}

void blockO::rotateCClock(){}

