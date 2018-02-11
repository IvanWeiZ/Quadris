//
//  board.h
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#ifndef __A5__board__
#define __A5__board__

#include <iostream>
#include <sstream>
#include "block.h"
#include "cell.h"
#include "nextBlock.h"
#include "window.h"

//some constant
extern const char clockwise;
extern const char conterclockwise;

class board{
    cell **theGrid; //contain all the cell that made board
    block *currentblock; //current block
    nextBlock *nb;  //a pointer to class next block
    bool lose; //state losing 
    TextDisplay *td; //pointer to textdispaly that dispaly all cell
    bool textmode; //graphic or not
    int Score,HiScore,Level; 
    Xwindow*w;

    void boardUpdate(int num, char direction); //update some cell in theGrid
    bool SpacetoRotate(vector *v); //check if there is space to rotate
    
public:
    board(nextBlock* nb, int level,bool textmode);
    ~board();
    //set level
    void setlevel(char c);
    
    //return true if fail, false otherwise, will update current block
    bool getNextblock();

    //return lose
    bool getLose();
    //return level
    int getLevel();
    
    //check how many cell we can move in certian direction
    int SpacetoRight();
    int SpacetoLeft();
    int SpacetoDown();
    
    //some command for that game to control board and current block
    void left(int num);
    void right(int num);
    void down(int num);
    void rotate(char direction);
    void restart();
    void drop();
    
    //These functions are used to calculate and update score
    void ScoreBlock(int l);
    bool isfull(int r);
    void delRow(int r);
    void delfull();
    void updateScore(int r);
    
    friend std::ostream &operator<<(std::ostream &out, const board &g);
};


#endif /* defined(__A5__board__) */
