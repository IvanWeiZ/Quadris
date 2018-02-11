//
//  main.cpp
//  A5
//
//  Created by Wei Zheng on 3/31/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "nextBlock.h"
#include "board.h"
#include "string"

using namespace std;

const char clockwise='C';
const char conterclockwise='R';

/*This function will consume a string s, and if the string start with
  "do" then return "down, "dr" return "drop" etc
  return a empty string if no match*/
string getCommand(string s){
  //down and drop
   if (s[0] == 'd'){
        if (s[1] == 'o') {
            return "down";
        }
        else if(s[1] == 'r')
            return "drop";
    }
   //right and restart
    else if(s[0] == 'r'){
        if(s[1]=='i'){
            return "right";
        }
        else if(s[1]=='e'){
            return "restart";
        }
    }
   //clockwise and counterclockwise
    else if(s[0] == 'c'){
        if (s[1] == 'l'){
            return "clockwise";
        }
        else if (s[1] == 'o'){
            return "counterclockwise";
        }
    }
   //left ,levelup and leveldown
    else if (s[0] == 'l'){
        if (s[2] == 'f'){
            return "left";
        }
        else if (s[5] == 'u'){
            return "levelup";
        }
        else if (s[5] == 'd'){
            return "leveldown";
        }
    }
   
    return "";
}


//main
int main(int argc, char* argv[]) {
    //_____________Get variable from command line______________
    string s;
    string sequence_char="";
    int level=0;
    int seed=1;
    bool textmode=false;
    
    int i=1;
    while(i<argc){
        s=argv[i];
	
	//get start level
        if(s=="-startlevel"){
            i++;
            level=atoi(argv[i]);
        }
	//textmode
        else if (s=="-text"){
            textmode=true;
        }

	//get all chars from the file to sequnce_char
        else if (s=="-scriptfile"){
            ifstream f;
            string temp;
            i++;
            string s1=argv[i];
            f.open(s1.c_str());
            while (f>>temp){ 
                sequence_char=sequence_char+temp;
            }
        }

	//seed
        else if(s=="-seed"){
            i++;
            seed=atoi(argv[i]);
        }
        i++;
    }

    //a if statement that change level to 1 if no scriptfile is provided and level is 0
    if (sequence_char==""&&level==0){
	cout<<"The file is empty or it is not readable"<<endl;
	cout<<"Level changed to 1"<<endl;
	level=1;}
    
    //_____________setup required variable and pass input___________________
    //nextBlock
    nextBlock *nb=new nextBlock(level,0,sequence_char,seed);
    //set seed for nextblock
    nb->setSeed(seed);
    
    //create board
    board b(nb,level,textmode);

    
    string input_str;
    nb->genNextblock();
    b.getNextblock();
    cout<<b;
    string command;
    int command_num=1;
    
    //____________get command from cin____________________
    while(cin>>input_str){
        string s;
        istringstream ss(input_str);

	//seprate number and command
        ss>> command_num;
        ss>> command;
        if (command_num == 0){
            command = input_str;
            command_num = 1;
        }
    
        command = getCommand(command);
	
	//left 
        if(command=="left"){
            b.left(command_num);
        }

	//right
        else if(command=="right"){
            b.right(command_num);
        }
	
	//down
        else if(command=="down"){
            b.down(command_num);
        }

	//drop
        else if(command=="drop"){
            b.drop();
            b.delfull();
            b.getNextblock();}

	//clockwise
        else if(command=="clockwise"){
            b.rotate(clockwise);
        }

	//counterclockwise
        else if(command=="counterclockwise"){
            b.rotate(conterclockwise);
        }

	//levelup
        else if(command=="levelup"){
	  for (int i=0;i<command_num;i++){
            b.setlevel('U');
	  }
        }

	//leveldown
        else if(command=="leveldown"){
	  for (int i=0;i<command_num;i++){
	    if(b.getLevel()==1&&sequence_char==""){
		cout<<"There is not a valid sequence.txt"<<endl;
	    }
	    else{
            b.setlevel('D');}
	  }
        }
        
	//restart
        else if(command=="restart"){
            b.restart();
            b.getNextblock();
        }
        
	//print the board
        cout<<b;

	//check if there is space for nextblock
        if (b.getLose()==true){
            cout<<"There is no place for next block"<<endl;
            return 0;
        }
    }
}

