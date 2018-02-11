//
//  blockI.cc
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#include "blockI.h"



blockI::blockI(int level):dir(0){
    this->level=level;
    this->cellAlive=4;
    this->type='I';
    vector *v= new vector[4];
    v[0]=vector(3,0);
    v[1]=vector(3,1);
    v[2]=vector(3,2);
    v[3]=vector(3,3);
    this->parts=v;
}



void blockI::rotateClock(){
    if (dir==0) {
        vector *tmp=&parts[0];
        parts[3]=vector(tmp->x,tmp->y);
        parts[2]=vector(tmp->x-1,tmp->y);
        parts[1]=vector(tmp->x-2,tmp->y);
        parts[0]=vector(tmp->x-3,tmp->y);
        dir=1;
        return;
    }
    else{
        vector *tmp=&parts[3];
        parts[0]=vector(tmp->x,tmp->y);
        parts[1]=vector(tmp->x,tmp->y+1);
        parts[2]=vector(tmp->x,tmp->y+2);
        parts[3]=vector(tmp->x,tmp->y+3);
        dir=0;
        return;
    }
}

void blockI::rotateCClock(){
    rotateClock();
}
