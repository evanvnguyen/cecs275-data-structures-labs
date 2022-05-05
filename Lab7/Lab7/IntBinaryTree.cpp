#include <iostream>
#include "IntBinaryTree.h"

// Insert accepts a TreeNode pointer and a pointer to a nodePtr
// The function inserts the node into hte tree pointed to
// by the TreeNode pointer. This function is calle recursively
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode){
    
    if (nodePtr == nullptr) {
        nodePtr = newNode; // insert the node
    } else if (newNode->value < nodePtr->value) {
        insert(nodePtr->left, newNode); // search the left branch
    } else {
        insert(nodePtr->right, newNode); // search the right branch
    }
}

// insertNode creates a new  node to hold num as its value
// and passes it to the insert function
void IntBinaryTree::insertNode(int num){

    // pointer to a new node
    TreeNode *newNode = nullptr;

    // create a new node and store num in it
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = nullptr;

    // insert the node
    insert(root, newNode);
}

// displayInOrder member function displays the values 
// in the subtree pointed to by nodePtr, via inorder traversal
void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        std::cout << nodePtr->value << std::endl;
        displayInOrder(nodePtr->right);
    }
}

// the displayPreOrder member funcion displays the values
// in the subtree pointed to by nodePtr, via preorder traversal
void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
    if (nodePtr) {
        std::cout << nodePtr->value << std::endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

// displayPostOrder displays the values in the subtree
// pointed to by nodePtr, via postorder traversal
void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
    if (nodePtr) {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        std::cout << nodePtr->value << std::endl;
    }
}

// countNodes counts the nodes in a tree
int IntBinaryTree::countNodes(TreeNode *nodePtr) const {
    int count = 0; // count root node
    if (nodePtr == NULL){
        return 0;
    } else {
        count += countNodes(nodePtr->left);
        count += countNodes(nodePtr->right);
    }
    return count++ + 1;
}

// countLeaves counts the number of leaves in the tree
int IntBinaryTree::countLeaves(TreeNode *nodePtr) const {
    int count;
    if ( nodePtr == NULL ){
        return 0;
    }
    // if there is no left or right node, return 1
    if (nodePtr->left == NULL && nodePtr->right == NULL) {
        return 1;
    }
    else {
        count = countLeaves(nodePtr->left) + countLeaves(nodePtr->right);
        return count;
    }
}

IntBinaryTree::~IntBinaryTree() {

}