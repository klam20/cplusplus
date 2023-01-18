//Program to create 
//                  1) graph
//                  2) adjacency matrix of weighted edges
//                  3) A) function for finding all adjacent nodes to one node 
//                     B) function for finding if two nodes are connected
//Then employ Djikstra's algorithm to find shortest path from Node A to Node B
//Worst-case time complexities should be on order of 
//O(v) for finding adjacent nodes
//O(1) for finding if two nodes are connected
//Space complexity
//O(v^2) due to VxV matrix

#include <iostream>
#include "Graph.h" 

using namespace std;

int main(){
    Graph g1(10);
    g1.makeEdge(4,8,34);
    g1.printWeightedAdjMatrix();
    
    return 0;
}