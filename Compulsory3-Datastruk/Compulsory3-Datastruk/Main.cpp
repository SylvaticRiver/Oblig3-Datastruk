#include "Main.h"
#include "Trees.h"
#include "Graphs.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//hvis error om at den ikke kan write:
//taskkill /F /IM Tre.exe

void execTree() {
	Tree tree = Tree::Tree();

	tree.root = tree.newNode(8);
	tree.root->children.push_back(tree.newNode(10));
	tree.root->children.push_back(tree.newNode(5));
	tree.root->children.push_back(tree.newNode(17));
	tree.root->children[0]->children.push_back(tree.newNode(86));
	tree.root->children[0]->children.push_back(tree.newNode(57));
	tree.root->children[1]->children.push_back(tree.newNode(38));
	tree.root->children[2]->children.push_back(tree.newNode(15));

	tree.insertNodeAtRandom(tree.newNode(71));

	//tree.insertNode(tree.root->children[2], tree.newNode(102));

	cout << "Level Order Traversal: ";
	tree.levelOrderTraversal(tree.root);
	cout << " " << endl;

	//int i = tree.getParent(tree.root->children[2]->children[0])->data;

	//bool bol = tree.isLeaf(root->children[2]->children[0]);

	//bool bol = tree.isRoot(root->children[1]);

	//int i = tree.getNodeDepth(root->children[1]->children[0]);

	//int i = tree.getSize(tree.root);

	//cout << i << endl;
}

void execGraphs() {
	Graph g = Graph::Graph(vector<int> {0, 1, 2, 3});

	Graph::Node* n0 = g.getNode(0);
	Graph::Node* n1 = g.getNode(1);
	Graph::Node* n2 = g.getNode(2);
	Graph::Node* n3 = g.getNode(3);
	//Graph::Node* n4 = g.getNode(4);
	map<Graph::Node*, bool> visited;

	g.addEdge(n0, n1);
	g.addEdge(n0, n2);
	g.addEdge(n1, n2);
	g.addEdge(n2, n0);
	//g.addEdge(n2, n4);
	g.addEdge(n2, n3);
	g.addEdge(n3, n3);

	//g.insertAsChild(n2, 4);
	//g.insertAsChild(n2, 5);

	g.DFS(n1, visited);

	//g.deleteNode(n0);

	//g.insertAtRandom(6);

	cout << " " << endl;
	vector<pair<Graph::Node*, Graph::Node*>> v = g.getEdges();

	for (pair<Graph::Node*, Graph::Node*> edge : v) {
		std::cout << "(" << edge.first->data << ", " << edge.second->data << ") ";
	}
	std::cout << std::endl;
}

int main()
{
	execGraphs();
	return 0;
}
