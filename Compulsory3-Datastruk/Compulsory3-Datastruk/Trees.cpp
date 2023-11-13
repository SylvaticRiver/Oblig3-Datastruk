#pragma once
#include "Trees.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

Tree::Tree() {
    root = nullptr;
}

Tree::Node* Tree::newNode(int data)
{
    Node* temp = new Node(data);
    return temp;
}

void Tree::levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        while (n > 0)
        {
            Node* current = q.front();
            q.pop();
            if (current != nullptr) {
                cout << current->data << " ";

                for (int i = 0; i < current->children.size(); i++)
                    q.push(current->children[i]);
                n--;
            }
        }
        cout << endl; 
    }
}

Tree::Node* Tree::getRoot()
{
    return this->root;
}

Tree::Node* Tree::getParent(Node* node)
{
    if (root == node) {
        return nullptr;
    }

    //I am literally just using LevelOrderTraversal here to traverse the tree, but instead of printing stuff out
    //I just check if one of the queued nodes have a child node
    //that matches the node we're checking

    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        while (n > 0)
        {
            Node* current = q.front();
            q.pop();
            if (current != nullptr) {
                for (int i = 0; i < current->children.size(); i++) {
                    Node* child = current->children[i];
                    if (child == node) {
                        n = 0;
                        return current;
                    }
                    q.push(child);
                    n--;
                }
            }
        }
    }

    return nullptr;
}

vector<Tree::Node*> Tree::getChildren(Node* node)
{
    return node->children;
}

int Tree::getSize(Node* node)
{
    //I'm basically just recursing through the tree adding for every node and its children. then returning the total + 1 to account for the root
    int size = 0;
    for (Node* child : node->children) {
        size += getSize(child);
    }
    return size + 1;
}

int Tree::getNodeDepth(Node* node) {
    if (root == nullptr) {
        return -1;
    }

    if (root == node) {
        return 0;
    }

    //I'm using a pair to associate a value with a node. I tried to use traversal like when I found parent
    //but kinda gave up on that and tried maps instead, then I ran into pairs
    //I decided to use pairs since they remind me a lot of maps in java, except only taking two values which is perfect here

    queue<pair<Node*, int>> q;
    q.push({ root, 0 });

    while (!q.empty()) {
        Node* current = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (current == node) {
            return depth;
        }

        for (Node* child : current->children) {
            q.push({ child, depth + 1 });
        }
    }

    return -1;
}



bool Tree::isLeaf(Node* node)
{
    return node->children.empty();
}

bool Tree::isRoot(Node* node)
{
    return node == this->root;
}

bool Tree::isEmpty()
{
    return this->root == NULL;
}

void Tree::insertNode(Node* current, Node* added) {
    current->children.push_back(added);
}

void Tree::insertNodeAtRandom(Node* added) {

    int size = getSize(root);
    int random = rand() % size;

    vector<Node*> nodes;
    queue<Node*> q;
    nodes.push_back(root);
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        while (n > 0)
        {
            Node* current = q.front();
            q.pop();
            if (current != nullptr) {
                for (int i = 0; i < current->children.size(); i++) {
                    nodes.push_back(current->children[i]);
                    q.push(current->children[i]);
                }
                n--;
            }
        }
    }
    Node* parent = nodes[random - 1];
    insertNode(parent, added);
}

void Tree::deleteNode(Node* deleted)
{
    if (deleted == root) {
        root = NULL;
        return;
    }

    //I use recursion to delete every node in the sub-tree
    Node* parent = getParent(deleted);
    for (Node* child : deleted->children) {
        deleteNode(child);
    }
    //I Erase the the spot containing the soon-to-be deleted node, then I delete it
    for (int i = 0; i < parent->children.size(); i++) {
        Node* child = parent->children[i];
        if (child == deleted) {
            parent->children.erase(parent->children.begin() + i);
        }
    }

    delete deleted;
}
