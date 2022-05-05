#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H
#include <iostream>

class IntBinaryTree{
    private:
        struct TreeNode{
            int value; // value in the node
            TreeNode *left; // pointer to the left child node
            TreeNode *right; // pointer ot the right child node
        };

        // pointer to the root node
        TreeNode *root;

        // Private member functions
        void insert(TreeNode *&, TreeNode *&);
        void displayInOrder(TreeNode *) const;
        void displayPreOrder(TreeNode *) const;
        void displayPostOrder(TreeNode *) const;
        int countNodes(TreeNode *) const;
        int countLeaves(TreeNode *) const;

    public:
        // constructor
        IntBinaryTree() 
            { root = nullptr; }

        // Destructor
        ~IntBinaryTree();

        // binary tree operations
        void insertNode(int);

        void displayInOrder() const 
            { displayInOrder(root); }

        void displayPreOrder() const
            { displayPreOrder(root); }

        void displayPostOrder() const 
            { displayPostOrder(root); }

        void displayCountNodes() const
            { std::cout << countNodes(root); }
            
        void displayCountLeaves() const 
            { std::cout << countLeaves(root); }
};

#endif