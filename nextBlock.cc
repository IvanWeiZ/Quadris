//
//  nextBlock.cc
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#include "nextBlock.h"
using namespace std;


char nextBlock::getNextType(){
    return NextBlock->gettype();
}

block* nextBlock::getNextblock(){
    block*btemp=NextBlock;
    genNextblock();
    return btemp;
}

//constructor
nextBlock::nextBlock(int level,int j,string s,int seed):level(level),j(j),s(s),seed(seed){
    srand(seed);
}

//destrutor
nextBlock::~nextBlock(){
    delete NextBlock;
}

//return next block 
block* nextBlock::getnbWithoutGen(){
    return NextBlock;
}

//set seed,level and string for the file
void nextBlock::setSeed(int seed){
    this->seed=seed;
}

void nextBlock::setString(std::string s){
    this->s=s;
}


void nextBlock::setLevel(int level){
    this->level=level;
    NextBlock->setLevel(level);
}

void nextBlock::restart(){
    this->j=0;
}

bool nextBlock::genNextblock(){
    char c=' ';
    int i=0;
    //level 0
    if(level==0){
        if(int(s.length())==0){
            return true;
        }
        else if(j<int(s.length())){
            c=s[j];
            j++;
        }
        else{
            j=0;
            c=s[j];
            j++;
        }
    }

    //level 1
    else if(level==1){
        i=rand()%12+1;//1-12
        if(i==1||i==2){
            c='I';
        }
        else if(i==3||i==4){
            c='J';
        }
        else if(i==5||i==6){
            c='L';
        }
        else if(i==7||i==8){
            c='O';
        }
        else if(i==9||i==10){
            c='T';
        }
        else if(i==11){
            c='S';
        }
        else{
            c='Z';
        }
    }
    else if(level==2){
        i=rand()%7+1;;
        if(i==1){
            c='I';
        }
        else if(i==2){
            c='J';
        }
        else if(i==3){
            c='L';
        }
        else if(i==4){
            c='O';
        }
        else if(i==5){
            c='T';
        }
        else if(i==6){
            c='S';
        }
        else{
            c='Z';
        }
    }

    //level 3
    else{
        i=rand()%9+1;;
        if(i==1){
            c='I';
        }
        else if(i==2){
            c='J';
        }
        else if(i==3){
            c='L';
        }
        else if(i==4){
            c='O';
        }
        else if(i==5){
            c='T';
        }
        else if(i==7||i==6){
            c='S';
        }
        else{
            c='Z';
        }
    }

    //generate a block
    switch(c){
        case 'I':NextBlock=new blockI(level);
            break;
        case 'J':NextBlock=new blockJ(level);
            break;
        case 'L':NextBlock=new blockL(level);
            break;
        case 'O':NextBlock=new blockO(level);
            break;
        case 'T':NextBlock=new blockT(level);
            break;
        case 'S':NextBlock=new blockS(level);
            break;
        default:NextBlock=new blockZ(level);
    }
    return false;
}

