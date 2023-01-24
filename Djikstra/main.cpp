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
#include "Djikstra.h"

using namespace std;

int main(){
    Djikstra g1(6); //parameter of 5 nodes

    //Make all the edges manually
    g1.makeEdge(0,1,5);
    g1.makeEdge(0,3,10);
    g1.makeEdge(1,4,2);
    g1.makeEdge(4,3,2);
    g1.makeEdge(1,2,11);
    g1.makeEdge(4,2,7);
    g1.makeEdge(4,5,3);
    g1.makeEdge(2,5,1);

    //Print weighted adjacancey matrix with 99999 as non-neighbors
    g1.printWeightedAdjMatrix();

    //Pass start node into algorithm
    g1.algorithm(0);

    //Print the result of algorithm
    g1.printDjikstra();

    //Print shortest path
    g1.getShortestPath(0,5);
    return 0;
}