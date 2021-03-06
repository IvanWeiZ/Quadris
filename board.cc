//
//  board.cc
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#include "board.h"

using namespace std;

//constructor
board::board(nextBlock *nb, int level=0,bool textmode=false){
  //init the theGrid
    theGrid=new cell*[maxRow];
    for(int i=0;i<maxRow;i++){
        theGrid[i]=new cell[maxCol];
    }
    
    for(int i=0;i<maxRow;i++){
        for (int j=0;j<maxCol;j++){
            (theGrid[i])[j].setCoords(i,j);}}
    //init other vars
    td=new TextDisplay();
    lose=false;
    currentblock=0;
    this->textmode=textmode;
    this->Level=level;
    Score=0;
    HiScore=0;
    this->nb=nb;

    //check to see if we need graphic or not
    if (textmode==false){
        Xwindow*w=new Xwindow(300,800);
        this->w=w;
    }
    else{
        this->w=NULL;
    }
    for(int i=0;i<maxRow;i++){
        for (int j=0;j<maxCol;j++){
            theGrid[i][j].setWindow(w);}}

}

//destructor
board::~board(){
  restart();
  delete td;
  delete nb;
  delete w;
}


//update the cells in coors as parts in current block, in direction and num cells
void board::boardUpdate(int num, char direction){
    vector *v=currentblock->getParts();
    for(int i=0;i<4;i++){
        theGrid[v[i].x][v[i].y].setNull();
        theGrid[v[i].x][v[i].y].notifyDisplay(*td,textmode);
    }
    if (direction==Down){
        currentblock->updateBlock(num, Down);
    }
    else if (direction==Right){
        currentblock->updateBlock(num, Right);
    }
    else if (direction==Left){
        currentblock->updateBlock(num, Left);
    }
    for (int i=0;i<4;i++){
        theGrid[v[i].x][v[i].y].setChar(currentblock->gettype());
        theGrid[v[i].x][v[i].y].notifyDisplay(*td,textmode);
        theGrid[v[i].x][v[i].y].setBlock(currentblock);
    }
    
}



//update level
void board::setlevel(char c){
    if(c=='D'){
	  if(Level!=0){
        	Level--;
        	nb->setLevel(Level);}}
    else{
	if(Level<3){
        	Level++;
        	nb->setLevel(Level);}}
}

//get next block and gen next next block
bool board::getNextblock(){
    currentblock=nb->getNextblock();
    vector *q=currentblock->getParts();
    char c=currentblock->gettype();

    //check if there is space
    for (int i=0;i<4;i++){
        int x=q[i].x;
        int y=q[i].y;
        if (theGrid[x][y].getOn()==true){
            lose=true;
    }}
    
    //set new block
    for (int i=0;i<4;i++){
        int x=q[i].x;
        int y=q[i].y;
        theGrid[x][y].setChar(c);
        theGrid[x][y].notifyDisplay(*td,textmode);
        theGrid[x][y].setBlock(currentblock);
    }

    if (nb->getnbWithoutGen()==0){
        return true;
    }
    return false;
}


bool board::getLose(){
    return lose;
}

int board::getLevel(){
    return Level;
}

//check if there is space to rotate, right ,left,down
bool board::SpacetoRotate(vector *v){
    vector v1=v[0];
    vector v2=v[1];
    vector v3=v[2];
    vector v4=v[3];
    for(int i=0;i<4;i++){
        if(v[i].x<0||v[i].x>14||v[i].y<0||v[i].y>9){
            return false;
        }
    }
    return ((!theGrid[v1.x][v1.y].getOn()||theGrid[v1.x][v1.y].compareBlock(currentblock))&&(!theGrid[v2.x][v2.y].getOn()||theGrid[v2.x][v2.y].compareBlock(currentblock))&&(!theGrid[v3.x][v3.y].getOn()||theGrid[v3.x][v3.y].compareBlock(currentblock))&&(!theGrid[v4.x][v4.y].getOn()||theGrid[v4.x][v4.y].compareBlock(currentblock)));
}




int board::SpacetoRight(){
    vector * v=currentblock->getParts();
    vector v1=v[0];
    vector v2=v[1];
    vector v3=v[2];
    vector v4=v[3];
    int counter=0;
    v1.y++;
    v2.y++;
    v3.y++;
    v4.y++;
    if(v1.y>9||v2.y>9||v3.y>9||v4.y>9){
        return counter;
    }
    
    while ((!theGrid[v1.x][v1.y].getOn()||theGrid[v1.x][v1.y].compareBlock(currentblock))&&(!theGrid[v2.x][v2.y].getOn()||theGrid[v2.x][v2.y].compareBlock(currentblock))&&(!theGrid[v3.x][v3.y].getOn()||theGrid[v3.x][v3.y].compareBlock(currentblock))&&(!theGrid[v4.x][v4.y].getOn()||theGrid[v4.x][v4.y].compareBlock(currentblock))){
        v1.y++;
        v2.y++;
        v3.y++;
        v4.y++;
        counter++;
        if(v1.y>9||v2.y>9||v3.y>9||v4.y>9){
            return counter;
        }
    }
    return counter;
}

int board::SpacetoLeft(){
    vector * v=currentblock->getParts();
    vector v1=v[0];
    vector v2=v[1];
    vector v3=v[2];
    vector v4=v[3];
    int counter=0;
    v1.y--;
    v2.y--;
    v3.y--;
    v4.y--;
    if(v1.y<0||v2.y<0||v3.y<0||v4.y<0){
        return counter;
    }
    while ((!theGrid[v1.x][v1.y].getOn()||theGrid[v1.x][v1.y].compareBlock(currentblock))&&(!theGrid[v2.x][v2.y].getOn()||theGrid[v2.x][v2.y].compareBlock(currentblock))&&(!theGrid[v3.x][v3.y].getOn()||theGrid[v3.x][v3.y].compareBlock(currentblock))&&(!theGrid[v4.x][v4.y].getOn()||theGrid[v4.x][v4.y].compareBlock(currentblock))){
        v1.y--;
        v2.y--;
        v3.y--;
        v4.y--;
        counter++;
        if(v1.y<0||v2.y<0||v3.y<0||v4.y<0){
            return counter;
        }
    }
    return counter;
}

int board::SpacetoDown(){
    vector * v=currentblock->getParts();
    vector v1=v[0];
    vector v2=v[1];
    vector v3=v[2];
    vector v4=v[3];
    int counter=0;
    v1.x++;
    v2.x++;
    v3.x++;
    v4.x++;
    if(v1.x>14||v2.x>14||v3.x>14||v4.x>14){
        return counter;
    }
    while ((!theGrid[v1.x][v1.y].getOn()||theGrid[v1.x][v1.y].compareBlock(currentblock))&&(!theGrid[v2.x][v2.y].getOn()||theGrid[v2.x][v2.y].compareBlock(currentblock))&&(!theGrid[v3.x][v3.y].getOn()||theGrid[v3.x][v3.y].compareBlock(currentblock))&&(!theGrid[v4.x][v4.y].getOn()||theGrid[v4.x][v4.y].compareBlock(currentblock))){
        counter++;
        v1.x++;
        v2.x++;
        v3.x++;
        v4.x++;
        if(v1.x>14||v2.x>14||v3.x>14||v4.x>14){
            return counter;
        }
    }
    return counter;
}

//functions used to control the game
void board::left(int num){
    int space=SpacetoLeft();
    if(num>space){
        boardUpdate(space, Left);
    }
    else{
        boardUpdate(num, Left);}
    
}
void board::right(int num){
    int space=SpacetoRight();
    if(num>space){
        boardUpdate(space, Right);
    }
    else{
        boardUpdate(num, Right);}
}

void board::down(int num){
    int space=SpacetoDown();
    if(num>space){
        boardUpdate(space, Down);
    }
    else{
        boardUpdate(num, Down);}
}
void board::rotate(char direction){
    vector *v1=currentblock->getParts();
    vector *temp=new vector[4];
    for (int i=0;i<4;i++){
        temp[i]=v1[i];
    }
    if(direction==clockwise){
        currentblock->rotateClock();
    }
    else{
        currentblock->rotateCClock();
    }
    if(!SpacetoRotate(v1)){
        currentblock->setParts(temp);
    }
    else{
        vector *v=currentblock->getParts();
        for(int i=0;i<4;i++){
            theGrid[temp[i].x][temp[i].y].setNull();
            theGrid[temp[i].x][temp[i].y].notifyDisplay(*td,textmode);
        };
        delete []temp;
        for (int i=0;i<4;i++){
            theGrid[v[i].x][v[i].y].setChar(currentblock->gettype());
            theGrid[v[i].x][v[i].y].notifyDisplay(*td,textmode);
            theGrid[v[i].x][v[i].y].setBlock(currentblock);
        }
    }
}


void board::restart(){
    nb->restart();
    Score=0;
    for(int i=0;i<15;i++){
        for (int j=0;j<10;j++){
            if(theGrid[i][j].getOn()){
                int alive = theGrid[i][j].getBlock()->getcellAlive();
                theGrid[i][j].setAlive(alive-1);
                if (alive == 1){
                    theGrid[i][j].DelBlock();
                }
                theGrid[i][j].setNull();
                theGrid[i][j].notifyDisplay(*td,textmode);
            }
        }
    }
}

void board::drop(){
    down(SpacetoDown());
}


//function used to calculate the score
bool board::isfull(int r){
    for (int i = 0; i < maxCol; i++){
        if (!theGrid[r][i].getOn()){
            return false;
        }
    }
    return true;
}

void board::ScoreBlock(int l){
    Score += (l+1) * (l+1);
    if (Score > HiScore) HiScore = Score;
}

void board::delRow(int r){
    for (int i = 0; i < maxCol; i++){
        int level = theGrid[r][i].getBlock()->getlevel();
        int alive = theGrid[r][i].getBlock()->getcellAlive();
        theGrid[r][i].setAlive(alive-1);
        if (alive == 1){
            ScoreBlock(level);
            theGrid[r][i].DelBlock();
        }
        theGrid[r][i].setNull();
        theGrid[r][i].notifyDisplay(*td,textmode);
        
        
    }
    for (int i = r; i > 0; --i){
        for (int j = 0; j < maxCol; ++j){
            if (theGrid[i-1][j].getOn()){
                char c = theGrid[i-1][j].getType();
                block *b = theGrid[i-1][j].getBlock();
                theGrid[i-1][j].setNull();
                theGrid[i-1][j].notifyDisplay(*td,textmode);
                theGrid[i][j].setBlock(b);
                theGrid[i][j].setChar(c);
                theGrid[i][j].notifyDisplay(*td,textmode);
                
            }
        }
    }
}


void board::delfull(){
    int count = 0;
    for (int i = 0; i < maxRow; ++i){
        if (isfull(i)){
            ++count;
            delRow(i);
        }
    }
    if (count != 0){
    updateScore(count);
    }
}

void board::updateScore(int r){
    Score += (Level + r) * (Level + r);
    if (Score > HiScore) HiScore = Score;
}



//output the board
std::ostream &operator<<(std::ostream &out,const board &g){
    if(!g.textmode){
        ostringstream ss1;
        ostringstream ss2;
        ostringstream ss3;
        ss1<<"Level:   "<<g.Level;
        ss2<<"Score:   "<<g.Score;
        ss3<<"HiScore: "<<g.HiScore;
        (g.w)->fillRectangle(0, 0, 300, 200,Xwindow::White);
        (g.w)->drawBigString(50,50,ss1.str());
        (g.w)->drawBigString(50,100,ss2.str());
        (g.w)->drawBigString(50,150,ss3.str());
    }
    
    
    out << "Level:         "<< g.Level<<endl;
    out << "Score:         "<< g.Score<<endl;
    out << "Hi Score:      "<< g.HiScore<<endl;
    out << "----------"<< endl;
    out<<*(g.td);
    out << "----------"<< endl;
    out << "Next:"<<endl;
    char c = g.nb->getNextType();
    if (!g.textmode){
        (g.w)->fillRectangle(0,670,300,130,Xwindow::White);
  	(g.w)->drawBigString(0, 190, "______________________________");
  	(g.w)->drawBigString(0, 645, "______________________________");
	(g.w)->drawBigString(50, 760, "Next:");
    }
    if (c == 'I'){
        out << "IIII      "<<endl;
        out << "          "<<endl;
        if(!g.textmode){
            (g.w)->fillRectangle(150,740,29,29,Xwindow::Blue);
            (g.w)->fillRectangle(180,740,29,29,Xwindow::Blue);
            (g.w)->fillRectangle(210,740,29,29,Xwindow::Blue);
            (g.w)->fillRectangle(240,740,29,29,Xwindow::Blue);
        }
        
    }
    else if (c == 'O'){
        out << "OO        "<<endl;
        out << "OO        "<<endl;
        if(!g.textmode){
            (g.w)->fillRectangle(150,740,29,29,Xwindow::Yellow);
            (g.w)->fillRectangle(180,740,29,29,Xwindow::Yellow);
            (g.w)->fillRectangle(150,710,29,29,Xwindow::Yellow);
            (g.w)->fillRectangle(180,710,29,29,Xwindow::Yellow);
        }

    }
    else if (c == 'J'){
        out << "J         "<<endl;
        out << "JJJ       "<<endl;
        if(!g.textmode){
            (g.w)->fillRectangle(150,740,29,29,Xwindow::Cyan);
            (g.w)->fillRectangle(180,740,29,29,Xwindow::Cyan);
            (g.w)->fillRectangle(210,740,29,29,Xwindow::Cyan);
            (g.w)->fillRectangle(150,710,29,29,Xwindow::Cyan);
        }

    }
    else if (c == 'T'){
        out << "TTT       "<<endl;
        out << " T        "<<endl;
        if(!g.textmode){
            (g.w)->fillRectangle(150,710,29,29,Xwindow::Red);
            (g.w)->fillRectangle(180,710,29,29,Xwindow::Red);
            (g.w)->fillRectangle(210,710,29,29,Xwindow::Red);
            (g.w)->fillRectangle(180,740,29,29,Xwindow::Red);
        }

    }
    else if (c == 'Z'){
        out << "ZZ        "<<endl;
        out << " ZZ       "<<endl;
        if(!g.textmode){
            (g.w)->fillRectangle(150,710,29,29,Xwindow::Brown);
            (g.w)->fillRectangle(180,740,29,29,Xwindow::Brown);
            (g.w)->fillRectangle(210,740,29,29,Xwindow::Brown);
            (g.w)->fillRectangle(180,710,29,29,Xwindow::Brown);
        }

    }
    else if (c == 'S'){
        out << " SS       "<<endl;
        out << "SS        "<<endl;
        if(!g.textmode){
            (g.w)->fillRectangle(150,740,29,29,Xwindow::Orange);
            (g.w)->fillRectangle(180,740,29,29,Xwindow::Orange);
            (g.w)->fillRectangle(210,710,29,29,Xwindow::Orange);
            (g.w)->fillRectangle(180,710,29,29,Xwindow::Orange);
        }

    }
    else if (c =='L'){
        out << "  L       "<<endl;
        out << "LLL       "<<endl;
        if(!g.textmode){
            (g.w)->fillRectangle(150,740,29,29,Xwindow::Green);
            (g.w)->fillRectangle(180,740,29,29,Xwindow::Green);
            (g.w)->fillRectangle(210,740,29,29,Xwindow::Green);
            (g.w)->fillRectangle(210,710,29,29,Xwindow::Green);
        }
    }
    return out;
}
