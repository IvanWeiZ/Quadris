//
//  blockL.cpp
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#include "blockL.h"


blockL::blockL(int level):dir(0){
    this->level=level;
    this->cellAlive=4;
    this->type='L';
    vector *v= new vector[4];
    v[0]=vector(3,2);
    v[1]=vector(4,0);
    v[2]=vector(4,1);
    v[3]=vector(4,2);
    this->parts=v;
}


//use dir to find a way to rotate
void blockL::rotateClock(){
    int c,r;
    if (dir==0){
        vector *tmp=&parts[1];
        r=tmp->x;
        c=tmp->y;
        parts[3]=vector(r,c+1);
        parts[2]=vector(r,c);
        parts[1]=vector(r-1,c);
        parts[0]=vector(r-2,c);
        dir=1;
        return;
    }
    else if (dir==1){
        vector *tmp=&parts[2];
        r=tmp->x;
        c=tmp->y;
        parts[0]=vector(r-1,c);
        parts[1]=vector(r-1,c+1);
        parts[2]=vector(r-1,c+2);
        parts[3]=vector(r,c);
        dir=2;
        return;
    }
    else if (dir==2){
        vector *tmp=&parts[0];
        r=tmp->x;
        c=tmp->y;
        parts[3]=vector(r+2,c+1);
        parts[2]=vector(r+1,c+1);
        parts[1]=vector(r,c+1);
        parts[0]=vector(r,c);
        dir=3;
        return;
    }
    else if (dir==3){
        vector *tmp=&parts[3];
        r=tmp->x;
        c=tmp->y;
        parts[0]=vector(r-1,c+1);
        parts[1]=vector(r,c-1);
        parts[2]=vector(r,c);
        parts[3]=vector(r,c+1);
        dir=0;
        return;
    }
}

void blockL::rotateCClock(){
    rotateClock();
    rotateClock();
    rotateClock();
}



