#include "Graphs.h"
#include <map>
#include <list>
#include <vector>

using namespace std;

Graph::Graph(vector<int> node)
{
    for (int i = 0; i < node.size(); i++) {
        nodes.push_back(newNode(node[i]));
    }
}

Graph::Node* Graph::newNode(int val)
{
    Node* temp = new Node(val);
    return temp;
}

Graph::Node* Graph::getNode(int val)
{
    return nodes[val];
}

int Graph::getNodeData(Node* node)
{
    return node->data;
}

vector<Graph::Node*> Graph::getNeighbors(Node* node)
{
    return node->neighbor;
}

list<Graph::Node*> Graph::getAdj(Node* node)
{
    return adj[node];
}

vector<Graph::Node*> Graph::getVerticies()
{
    return nodes;
}

int Graph::size() {
    return nodes.size();
}

bool Graph::isEmpty() {
    return nodes.empty();
}

vector<pair<Graph::Node*, Graph::Node*>> Graph::getEdges()
{
    vector<pair<Node*, Node*>> v;
    for (Node* node : nodes) {
        for (Node* second : adj[node]) {
            v.push_back(pair<Node*, Node*>(node, second));
        }
    }
    return v;
}

void Graph::insertAsChild(Node* parent, int value)
{
    Node* node = newNode(value);
    nodes.push_back(node);
    addEdge(parent, node);
}

void Graph::insertAtRandom(int value)
{
    int random = rand() % size();

    insertAsChild(nodes[random], value);
}

void Graph::deleteNode(Node* node)
{
    for (Node* other : nodes) {
        adj[other].remove(node);
    }
    adj.erase(node);
    delete node;
}


void Graph::addEdge(Node* node1, Node* node2)
{
    node1->neighbor.push_back(node2);
    node2->neighbor.push_back(node1);
    adj[node1].push_back(node2);
}

void Graph::deleteEdge(Node* node1, Node* node2)
{
    adj[node1].remove(node2);
}

void Graph::DFS(Node* node, map<Node*, bool> visited)
{
    visited[node] = true;
    cout << node->data << " ";

    list<Node*>::iterator i;
    for (i = adj[node].begin(); i != adj[node].end(); ++i) {
        if (!visited[*i]) {
            DFS(*i, visited);
        }
    }
}
