//
//  cell.cc
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#include "cell.h"

cell::cell():row(0),col(0),b(0),type(' '),isOn(false),w(0){
}

void cell::setNull(){
    b=NULL;
    type=' ';
    isOn=false;
}

void cell::setWindow(Xwindow*w){
    this->w=w;
}

bool cell::getOn(){
    return isOn;
}

void cell::setAlive(int n){
    b->setcellAlive(n);
}

void cell::DelBlock(){
    delete b;
}

char cell::getType(){
    return type;
}

block* cell::getBlock(){
    return b;
}

bool cell::compareBlock(block *b){
    return this->b==b;
}

void cell::setBlock(block *b){
    this->b=b;
}

void cell::setChar(char ch){
    if(ch!=' '){
        isOn = true;
    }
    else{
        isOn = false;
    }
    this->type = ch;
}

void cell::setCoords(int x, int y){
    row=x;
    col=y;
}

//graphic or only text
void cell::notifyDisplay(TextDisplay &td,bool textmode){
    if (textmode){
        if (isOn){
            td.notify(row, col, type);
        }
        else{
            td.notify(row, col, ' ');
        }
    }
    else{
        if (isOn){
            td.notify(row, col, type);
            draw();
        }
        else{
            td.notify(row, col, ' ');
            undraw();
        }
        
    }
}

//draw depend on the type
void cell::draw(){
    switch (type) {
        case 'L':
            w->fillRectangle(col*30, row*30+200, 29, 29,Xwindow::Green);
            break;
        case 'S':
            w->fillRectangle(col*30, row*30+200, 29, 29,Xwindow::Orange);
            break;
        case 'Z':
            w->fillRectangle(col*30, row*30+200, 29, 29,Xwindow::Brown);
            break;
            
        case 'I':
            w->fillRectangle(col*30, row*30+200, 29, 29,Xwindow::Blue);
            break;
            
        case 'J':
            w->fillRectangle(col*30, row*30+200, 29, 29,Xwindow::Cyan);
            break;
            
        case 'O':
            w->fillRectangle(col*30, row*30+200, 29, 29,Xwindow::Yellow);
            break;
            
        case 'T':
            w->fillRectangle(col*30, row*30+200, 29, 29,Xwindow::Red);
            break;
    }
}
void cell::undraw(){
    w->fillRectangle(col*30, row*30+200, 30, 30,Xwindow::White);
}



cell::~cell(){
    delete b;
}
