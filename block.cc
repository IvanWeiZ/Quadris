//
//  block.cc
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#include "block.h"



const char Right='R';
const char Left='L';
const char Down='D';

//some simple return fields function 
int block::getlevel(){
    return level;
}

int block::getcellAlive(){
    return cellAlive;
}

char block::gettype(){
    return type;
}

vector* block::getParts(){
    return parts;
}


void block::updateBlock(int numCell, char direction){
  //down
    if (direction==Down){
        for(int i=0;i<4;i++){
            parts[i].x+=numCell;
        }
    }
    //right
    else if(direction==Right){
        for(int i=0;i<4;i++){
            parts[i].y+=numCell;
        }
        
    }
    //left
    else{
        for(int i=0;i<4;i++){
            parts[i].y-=numCell;
        }
    }
}

//some simple functions that set the fields in a block

void block::setcellAlive(int n){
    cellAlive=n;
}

void block::setParts(vector * v){
    delete [] parts;
    this->parts=v;
}

void block::setLevel(int level){
    this->level=level;
}

block::~block(){
    delete [] parts;
}


