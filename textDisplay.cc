//
//  textDisplay.cc
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#include "textDisplay.h"
const int maxRow=15;
const int maxCol=10;
using namespace std;


TextDisplay::TextDisplay(){
  //init the chars
    theDisplay = new char*[maxRow];
    for (int i = 0; i < maxRow; ++i){
        theDisplay[i] = new char[maxCol];
    }
    for (int i = 0; i < maxRow; ++i){
        for (int j = 0; j < maxCol; ++j){
            theDisplay[i][j] = ' ';
        }
    }
}

void TextDisplay::notify(int r, int c, char ch){
    theDisplay[r][c] = ch;
}

TextDisplay::~TextDisplay(){
    for (int i = 0; i < maxRow; ++i){
        delete [] theDisplay[i];
    }
    delete [] theDisplay;
}

ostream &operator<<(ostream &out,const TextDisplay &td){
    for (int i = 0; i < maxRow; ++i){
        for (int j = 0; j < maxCol; ++j){
            out << td.theDisplay[i][j];
        }
        cout<<endl;
    }
    return out;
}
