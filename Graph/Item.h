//
//  Header.h
//  Maze
//
//  Created by Kode Creer on 4/7/19.
//  Copyright © 2019 Kode Creer. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>

template <class T>
class Item {
    T value;
    int identification_num;
    
public:
    T& Value(){
        return value;
    }
    int& ID(){
        return identification_num;
    }
};

#endif /* Header_h */
