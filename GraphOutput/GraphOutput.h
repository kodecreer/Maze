//
//  GraphOutput.hpp
//  Maze
//
//  Created by Kode Creer on 4/24/19.
//  Copyright © 2019 Kode Creer. All rights reserved.
//

#ifndef GraphOutput_h
#define GraphOutput_h

#include <iostream>
#include "/Users/kodecreer/Documents/C++/DSandAlgs/Maze/Maze/Graph/Graph.h"

namespace GOut {
    template <class Item>
    void printGraphVisual(Graph<Item> g);
    
    template <class Item>
    void printGraph(Graph<Item> g);
}

#endif /* GraphOutput_hpp */
