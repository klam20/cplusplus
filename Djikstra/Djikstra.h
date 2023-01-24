//Graph needs to have adjacency matrix
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>

using namespace std;

class Djikstra {
    private:
        int numVertices;
        const int INFINITY = 99999; //large constant denoting infinity
        vector<vector<int>> weightedAdjMatrix;
        queue<int> bfsQueue;//Initialize set to act as queue //useful since find() operation exists already
        vector<int> visited; //At node(vector index) check if it has been visited //true means visited
        vector<int> shortestDist; //total shortest distance to current node from the source node
        vector<int> previousNode; //from the current node, this node will be the previous one on the shortest path

        void makeWeightedAdjMatrix() {
                    weightedAdjMatrix.resize(numVertices, vector<int>(numVertices, INFINITY)); //Vector of vectors think of it as a row, with each column having another vector
                                                                                                //should contain weights, with INFINITY meaning node is not connected
                    for (int l = 0; l < numVertices; l++) {
                        weightedAdjMatrix[l][l] = 0; //distance from a node to itself is 0
                    }
        }

        bool isInQueue(int node) {
            queue<int> bfsQueueCopy = bfsQueue; //Copy the bfsQueue
            //Pop items until a match is found
            while (!bfsQueueCopy.empty()) {
                if (bfsQueueCopy.front() == node) {
                    return true; //Race to see if true activates before false
                }
                bfsQueueCopy.pop(); //pop to look at next item in queue
            }
            return false;
        }

        bool allVisited() {
            //Need to check if there is only 1 item in visited array that is not -1;
            int count = 0;
            for (int i = 0; i < numVertices; i++) {
                if (visited[i] == -1) { //If item is already visited
                    count++; //Increment counter
                }
            }
            
            if (count == (numVertices-1)) { //If exactly one item is still unvisited
                return true; //Then all have been visited
            }
            else return false; //Not all have been visited
        }

        void algorithmHelper(int currentNode) { //This will be recursive passes
            if (allVisited()) { //If all visited then recursion stops, stack frame collapses
                return;
            }

            else {
                for (int i = 0; i < numVertices; i++) { //For all vertices
                    if (weightedAdjMatrix[currentNode][i] != INFINITY && visited[i] != -1) { //If it is a unvisited neighbor
                        if (!isInQueue(i)) { //If not in bfsQueue
                            bfsQueue.push(i); //Push into bfsQueue
                        } 

                        if (weightedAdjMatrix[currentNode][i] + shortestDist[currentNode] < shortestDist[i]) { //Check if distance from current node to neighbor
                                                                                                               //plus the shortest distance to the current node
                                                                                                               //is less than the current shortest distance for the neighbor
                            shortestDist[i] = weightedAdjMatrix[currentNode][i] + shortestDist[currentNode]; //Update neighbor shortest distance if true
                            previousNode[i] = currentNode; //Update with new previous node for that neighbor
                        }
                    }
                }
                visited[currentNode] = -1; //CurrentNode has been visted after
                bfsQueue.pop(); //pop the visited node off the queue, which is just the front of stack
                algorithmHelper(bfsQueue.front()); //Run algorithm helper on next item in queue
            }
        }



    public:
        Djikstra(int numVertices) { //Default constructor
            this->numVertices = numVertices;
            makeWeightedAdjMatrix(); //call to make an adj matrix
        }

        void printDjikstra() { //print vertex, shortest dist, previous node
            cout << "V" << "\tDist" << "\tprevNode" << endl;
            for (int i = 0; i < numVertices; i++) {
                cout << i << ": " << "\t" << shortestDist[i] << "\t" << previousNode[i] << endl;
            }
        }

        void printWeightedAdjMatrix() { //display adj matrix

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

        void algorithm(int sourceNode) { //This will be first pass
            for (int i = 0; i < numVertices; i++) {
                visited.push_back(i);
                shortestDist.push_back(INFINITY);
                previousNode.push_back(-1);
            }
            shortestDist[sourceNode] = 0; //Distance from sourceNode to sourceNode itself is 0
            bfsQueue.push(sourceNode); //Push into the BFS queue
            algorithmHelper(sourceNode); //Run the helper recursive function starting at sourceNode
        }

        void getShortestPath(int idxA, int idxB) { //return shortest path between node A and node B
            algorithm(idxA); //set sourceNode to be idxA      
            cout << "Path from " << idxA << " to " << idxB << ": ";    
            //Use recursive approach to print output backwards
            getShortestPathHelper(idxA, idxB);
            cout << idxB << endl;
            cout << endl;
            }

        void getShortestPathHelper(int idxA, int idxB) { //Recursive portion
             if (idxB == idxA) {
                return;
            }
            else {
                idxB = previousNode[idxB];
                getShortestPathHelper(idxA, idxB);
                cout << idxB << " ";
            }
        }

};

    