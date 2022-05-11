#ifndef Project4_MakeTree_hpp
#define Project4_MakeTree_hpp

#include<iostream>
#include<string>

#include "TreeNode.hpp"
#include "GraphNode.hpp"

class MakeTree {
public:
    //Constructor
    MakeTree();

    //Getters
    TreeNode *getRoot() { return _root; }

    //Functions
    void insert( GraphNode *nNode );
    GraphNode *find( std::string name ){ return findHelper(name, getRoot()); }
    void print() { print(_root); }

private:
    GraphNode *findHelper( std::string name, TreeNode *root);
    TreeNode *insert(TreeNode *tNode, GraphNode *nNode);
    void print(TreeNode *root);

    TreeNode *_root;
};

#endif
