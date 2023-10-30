#pragma once
#include "Trees.h"
#include <iostream>
#include "Vector"
#include "Queue"

using namespace std;

struct Node
{
    int value;
    vector<Node*>child;
};

Node* CreateNewNode(int value)
{
    Node* node = new Node;
    node->value = value;
    return node;
}

void BreadthTree(Node* root) {
    queue <Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
            Node* n = q.front();
            q.pop();
            cout << n->value << " ";
            for (int i = 0; i < n->child.size(); i++) {
                q.push(n->child[i]);
                size--;
            }
        }
        cout << endl;
    }
}

int main()
{
    Node* root = CreateNewNode(10);
    (root->child).push_back(CreateNewNode(2));
    (root->child).push_back(CreateNewNode(34));
    (root->child).push_back(CreateNewNode(56));
    (root->child).push_back(CreateNewNode(100));
    (root->child[0]->child).push_back(CreateNewNode(77));
    (root->child[0]->child).push_back(CreateNewNode(88));
    (root->child[2]->child).push_back(CreateNewNode(1));
    (root->child[3]->child).push_back(CreateNewNode(7));
    (root->child[3]->child).push_back(CreateNewNode(8));
    (root->child[3]->child).push_back(CreateNewNode(9));

    BreadthTree(root);

    return 0;
}
