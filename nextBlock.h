//
//  nextBlock.h
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#ifndef __A5__nextBlock__
#define __A5__nextBlock__

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "block.h"
#include "blockJ.h"
#include "blockI.h"
#include "blockT.h"
#include "blockS.h"
#include "blockO.h"
#include "blockZ.h"
#include "blockL.h"

class nextBlock{
    block *NextBlock;
    int level;
    int j;
    std::string s;
    int seed;
public:
    nextBlock(int level,int j,std::string s,int seed);
    ~nextBlock();
    block* getNextblock();
    block* getnbWithoutGen();
    char getNextType();
    bool genNextblock();
    void setLevel(int level);
    void setString(std::string s);
    void setSeed(int seed);
    void restart();
};
#endif /* defined(__A5__nextBlock__) */
