//
//  block.h
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#ifndef __A5__block__
#define __A5__block__

#include <iostream>

//some constant
extern const char Right;
extern const char Left;
extern const char Down;

//a simple class vector used in Block
struct vector{
    int x,y;
    vector(int x=0, int y=0):x(x),y(y){}
};

class block{
protected:
    int level;//level of that block
    int cellAlive;//number of cell alive
    char type; //Type of that block could be 'L' 'I' 'S' 'Z' 'J' 'T' 'O'
    vector *parts; //store coords of the cells
public:
    //get fields in block;
    int getlevel();
    int getcellAlive();
    char gettype();
    vector* getParts();
    
    //setfileds in block

    //this function will move the vectors in parts in direction and numCell cell
    void updateBlock(int numCell, char direction);
    void setcellAlive(int n);
    void setParts(vector *v);
    void setLevel(int level);
    
    //change the coords of a block by rotate
    virtual void rotateClock()=0;
    virtual void rotateCClock()=0;
    
    //destructor
    virtual ~block();
};


#endif /* defined(__A5__block__) */
