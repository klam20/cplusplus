
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

//Base template of Graph using Adjacency Matrix
class Graph {
    private:
        int numVertices; 
        const int INFINITY = 99999; //large constant denoting infinity
        vector<vector<int>> weightedAdjMatrix;

        void makeWeightedAdjMatrix() {
                    weightedAdjMatrix.resize(numVertices, vector<int>(numVertices, INFINITY)); //Vector of vectors think of it as a row, with each column having another vector
                                                                                                //should contain weights, with INFINITY meaning node is not connected
                    for (int l = 0; l < numVertices; l++) {
                        weightedAdjMatrix[l][l] = 0; //distance from a node to itself is 0
                    }
        };   

    public:
        Graph(int numVertices) { //Default constructor
            this->numVertices = numVertices;
            makeWeightedAdjMatrix(); //call to make an adj matrix
        }
        
        void printWeightedAdjMatrix() { //double for loop n^2 time complex to display adj matrix

            //Print column header
            cout << setw(13+3*(numVertices-1)) << "Col: " << endl; //Experiment with setw to get spacing of print
            cout << setw(5) << " ";
            for (int k = 0; k < numVertices; k++) {
                cout << setw(5) << k << " ";
            }
            cout << endl;

            //Print rows
            for (int i = 0; i < numVertices; i++) { //rows
                    cout << "Row " << i << ": ";
                for (int j = 0; j < numVertices; j++) { //cols
                    cout << setw(5) << weightedAdjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }                                                                                 

        void makeEdge(int idxA, int idxB, int weight) { //create an edge in O(1) constant time since this is just array indexing
            weightedAdjMatrix[idxA][idxB] = weight; //Edge from A to B is assigned weight != INFINITY
            weightedAdjMatrix[idxB][idxA] = weight;
        }

        
};