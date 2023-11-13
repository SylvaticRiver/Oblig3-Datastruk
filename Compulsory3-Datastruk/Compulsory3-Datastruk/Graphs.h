#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

class Graph {
public:
    struct Node {
        int data;
        vector<Node*> neighbor;

        Node(int val) {
            data = val;
        }
    };

    vector<Node*> nodes;
    map<Node*, list<Node*> > adj;

    Graph(vector<int> node);

    Node* newNode(int val);
    Node* getNode(int val);
    int getNodeData(Node* node);
    vector<Node*> getNeighbors(Node* node);
    list<Node*> getAdj(Node* node);
    vector<Node*> getVerticies();
    vector<pair<Node*, Node*>> getEdges();
    void insertAsChild(Node* parent, int value);
    void insertAtRandom(int value);
    void deleteNode(Node* node);
    int size();
    bool isEmpty();

    // Function to add an edge to graph
    void addEdge(Node* node1, Node* node2);
    void deleteEdge(Node* node1, Node* node2);

    void DFS(Node* node, map<Node*, bool> visited);
};
