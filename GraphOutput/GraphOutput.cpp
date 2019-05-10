//
//  GraphOutput.cpp
//  Maze
//
//  Created by Kode Creer on 4/24/19.
//  Copyright © 2019 Kode Creer. All rights reserved.
//

#include "GraphOutput.h"

template <class Item>
void GOut::printGraphVisual(Graph<Item> g){
    for (int i = 0; i < g.size(); ++i) {
        
        std::cout << g[i].ID();
        for (int b = 0; b < 4; ++b) {
            switch (g[i].directions()[b]) {
                case UP:
                    std::cout << "|^^^|";
                    break;
                case DOWN:
                    std::cout << "|vvv|";
                    break;
                case LEFT:
                    std::cout << "_<<<_";
                    break;
                case RIGHT:
                    std::cout <<"_>>>_";
                    break;
                default:
                    std::cout << "■■■■■";
                    break;
            }
        }
        std::cout << std::endl;
    }
    
}

template <class Item>
void GOut::printGraph(Graph<Item> g){
    for (int i = 0; i < g.size(); ++i) {
        
        std::cout << g[i].ID();
        
        for (auto i : g.neighbors(i)) {
            std::cout << " -> " << i;
        }
        std::cout << std::endl;
    }
    
}


