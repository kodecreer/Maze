//
//  main.cpp
//  Graphs
//
//  Created by Kode Creer on 2/22/19.
//  Copyright © 2019 Kode Creer. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Graph.h"
#include <queue>
#include "SearchFunctions.h"
//#include "GraphOutput/GraphOutput.h"
#include <fstream>
#include <vector>

template <class Item>
void printGraphVisual(Graph<Item> g){
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
void printGraph(Graph<Item> g){
    for (int i = 0; i < g.size(); ++i) {
        
        std::cout << g[i].ID();
        
        for (auto i : g.neighbors(i)) {
            std::cout << " -> " << i;
        }
        std::cout << std::endl;
    }
    
}
void printGraphLabels(Vertex<int> v){
    std::cout << "Current Node : " << v.Value() << std::endl;
}

void on_graph_success(Vertex<int> v){
    std::cout << "I found " << v.Value() << " which has an ID of " << v.ID() << std::endl;
}

//Same as the depth first funciton, but using a breadth first search instead

int main(int argc, const char * argv[]) {

    
//    int tapestryRow, tapestryColumn;
//    std::cout << "Welcome to the maze. The maze will be a 10 x 8 maze.\n:::\n You may place your tapestry and let the machine see if it can navigate out."  << std::endl;
//    do {
//        std::cout << "Which row is it in? (A number between 1 and 10" << std::endl;
//        std::cin >> tapestryRow;
//    } while (tapestryRow < 1 || tapestryRow > 10);
//
//    do {
//        std::cout << "Which column is it in? (A number between 1 and 8)" << std::endl;
//        std::cin >> tapestryColumn;
//    } while (tapestryColumn < 1 || tapestryColumn > 8);
    

//    std::ofstream points("Maze1.txt");
//    for (auto i : directions) {
//        for (int b = 0; b < 4; ++b) {
//            points << i[b];
//        }
//        points << std::endl;
//    }
//    return 0;
    const int numberAsciiAdjust = 48;
    int mazeSize, mazeHeight, mazeWidth;
    int k = 0;
    
    std::ifstream points("Maze2/Maze.txt");
    std::string height_str, width_str;
    points >> height_str >> width_str;
    
    mazeHeight = static_cast<int>(height_str[2] - numberAsciiAdjust);
    mazeWidth = static_cast<int>(width_str[2] - numberAsciiAdjust);
    mazeSize = mazeWidth * mazeHeight;
    
    direction directions[mazeSize][4];
    
    while (!points.eof()) {
        std::string numStr;
        points >> numStr;

        for (int b = 0; b < 4; ++b) {
            directions[k][b] = static_cast<direction>( numStr[b] - numberAsciiAdjust);
        }
        ++k;
    }
    
    Graph<Vertex<int>> numsSys = Graph<Vertex<int>>();

    for (int i = 0; i < mazeSize; ++i) {
        Vertex<int> vert = Vertex<int>( i, directions[i] );
        vert.ID() = i;
        numsSys.add_vertex(vert);
    }
    //call a init edged function that goes through each edge
    for (int i = 0; i < mazeSize; ++i) {
        for (int b = 0; b < 4; ++b) {
            switch (numsSys[i].directions()[b]) {
                case DOWN:{
                    numsSys.add_edge(i, i+1, 1);
                    break;
                }
                case UP:{
                    numsSys.add_edge(i, i-1, 1);
                    break;
                }
                case LEFT:{
                    numsSys.add_edge(i, i-mazeHeight, 1);
                    break;
                }
                case RIGHT:{
                    numsSys.add_edge(i, i+mazeHeight, 1);
                    break;
                }
                case NONE:{
                    //do nothing
                    break;
                }
            }
            
        }
    }
    
    printGraph(numsSys);
    //The range of the maze is 0 to 15. You can use anyone but the BFS and it will work to traverse the maze.
    //Remember that my maze is formated like this
    /*
     0  4   8   12
     1  5   9   13
     2  6   10  14
     3  7   11  15
     */
    const size_t start = 11;
    const size_t end = 12;
    depth_first(::printGraphLabels, ::on_graph_success, numsSys, start, end);
    //breadth_first(::printGraphLabels, numsSys, numsSys.size()/2+9);
    shortest_route(::printGraphLabels, numsSys, start, end);

    std::cout<<std::endl;
    return 0;
}
