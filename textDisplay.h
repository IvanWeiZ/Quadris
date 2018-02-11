//
//  textDisplay.h
//  A5
//
//  Created by Wei Zheng on 4/3/14.
//  Copyright (c) 2014 Wei Zheng. All rights reserved.
//

#ifndef __A5__textDisplay__
#define __A5__textDisplay__

#include <iostream>
extern const int maxRow;
extern const int maxCol;

class TextDisplay {
    char **theDisplay;
public:
    TextDisplay();
    void notify(int r, int c, char ch); //cell will call that function to change state
    ~TextDisplay();
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif /* defined(__A5__textDisplay__) */
