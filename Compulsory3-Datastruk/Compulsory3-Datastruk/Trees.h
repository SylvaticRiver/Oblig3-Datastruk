#define TREE_H

#include <iostream>
#include <queue>
#include <vector>

class Tree {
public:
    struct Node {
        int data;
        std::vector<Node*> children;

        Node(int val) {
            data = val;
        }
    };

    Node* root;

public:
    Tree();
    void levelOrderTraversal(Node* root);
    Node* newNode(int data);

    Node* getRoot();
    Node* getParent(Node* node);
    std::vector<Node*> getChildren(Node* node);

    int getSize(Node* node);
    int getNodeDepth(Node* node);
    bool isLeaf(Node* node);
    bool isRoot(Node* node);
    bool isEmpty();
    void insertNode(Node* current, Node* added);
    void insertNodeAtRandom(Node* added);
    void deleteNode(Node* deleted);
};
