/*
 * Answer to Lab 7
 * CECS 275 - Spring 2022 
 * @author Evan Nguyen  
 * @author Joseph Guzman
 * @version 1.0.0 
 *
 */


#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

int main() {

    IntBinaryTree tree;
    cout << "inserting nodes. \n";
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(8);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(7);
    tree.insertNode(12);

    cout << "displaying in order: \n";
    tree.displayInOrder();
    cout << "displaying in pre-order: \n";
    tree.displayPreOrder();
    cout << "displaying in post-order: \n";
    tree.displayPostOrder();
    cout << "Number of nodes in this tree: ";
    tree.displayCountNodes();
    cout << endl;
    cout << "Number of leaves in this tree: ";
    tree.displayCountLeaves();
    cout << endl;
    return 0;
}