//
//  cell.h
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#ifndef __A5__cell__
#define __A5__cell__

#include <iostream>
#include "block.h"
#include "textDisplay.h"
#include "window.h"
class cell{
protected:
    int row,col; // row and col is position of cell
    block * b;//block that cell belong to
    char type; // the chars types of block.
    bool isOn; // check the cell is empty or not.
    Xwindow*w;
    
public:
    cell();
    bool getOn(); // get isOn.
    void setChar(char ch); // set cell's type to ch.
    void setAlive(int n); //set number of alive
    void setWindow(Xwindow *w); 
    void DelBlock(); //delete block
    block* getBlock(); //return block
    void setCoords(int x,int y); //set coords for that cell
    void setBlock(block *b); //set block for that cell
    char getType(); //return type of the cell
    bool compareBlock(block *b); //compare the block with b
    void setNull(); //set block to null, and type to ' '
    void restart(); //clean data in that cell
    void notifyDisplay(TextDisplay &td,bool mode); // display cell to the text display.
    void draw();
    void undraw();
    ~cell();
};

#endif /* defined(__A5__cell__) */
