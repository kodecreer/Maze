//
//  Graph.h
//  Graphs
//
//  Created by Kode Creer on 3/5/19.
//  Copyright © 2019 Kode Creer. All rights reserved.
//

#ifndef Graph_h
#define Graph_h
#include <iostream>
#include <cstdlib>
#include <set>
#include "Vertex.hpp"
template <class Item>
class Graph{
public:
    //Member constants
    static const size_t MAXIMUM = 100;
    
    //CONSTRUCTOR
    Graph(){many_vertices = 0;};
    
    //MODIFICATION MEMEBER FUNCTIONS
    void add_vertex(const Item& label);
    
    void add_edge(size_t source, size_t target, size_t weight);
    
    void remove_edge(size_t source, size_t target);
    
    Item& operator [](size_t vertex);

    //CONSTANT MEMBER FUNCTIONS
    size_t size() const { return many_vertices;}
    
    bool is_edge(size_t source, size_t target) const;
    int edge_at(size_t source, size_t target) const;
    
    std::set<size_t> neighbors(size_t vertex) const;
    
    Item operator [] (size_t vertex) const;
    
    //DATA MEMBERS
private:
    bool bool_edges[MAXIMUM][MAXIMUM];
    int edges[MAXIMUM][MAXIMUM];
    Item labels[MAXIMUM];
    size_t many_vertices;
    
    
};

#include "Graph.template"
#endif /* Graph_h */
