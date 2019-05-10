//
//  Vertex.hpp
//  Maze
//
//  Created by Kode Creer on 4/10/19.
//  Copyright © 2019 Kode Creer. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include <iostream>

enum direction{
    LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3, NONE = 4
};

template <class T>
class Vertex {
    T value;
    int id;
    direction edge_locations[4];
public:
    Vertex(T value, direction locations[], int id=0){
        this->value = value;
        this->id = id;
        for(int i = 0; i < 4; ++i){
            this->edge_locations[i] = locations[i];
        }
    }
    Vertex(){
        for(int i = 0; i < 4; ++i){
            this->edge_locations[i] = NONE;
        }
    }
    bool operator ==(T val){
        return this->Value() == val;
    }
    T& Value(){
        return value;
    }
    int& ID(){
        return id;
    }
    direction* directions(){
        return this->edge_locations;
    }
};
//template <class T>
//std::ostream& operator << (std::ostream os, Vertex<T> v){
//    os << v.Value() << std::endl;
//    return os;
//}
#endif /* Vertex_hpp */
