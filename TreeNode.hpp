#ifndef Project4_TreeNode_hpp
#define Project4_TreeNode_hpp

#include<iostream>
#include<string>
#include "GraphNode.hpp"

class TreeNode {
public:
    //Constructor
    TreeNode( GraphNode *nNode );

    //Getters
    GraphNode *graphNode(){ return makeNode; };
    TreeNode *left() { return leftSubtree; }
    TreeNode *right() { return rightSubtree; }

    //Setters
    void left( TreeNode *leftPtr ) { leftSubtree = leftPtr; }
    void right( TreeNode *rightPtr ) { rightSubtree = rightPtr; };

    //Functions
    void print(){ makeNode->print(); }

private:
    GraphNode *makeNode;
    TreeNode *leftSubtree, *rightSubtree;
};

#endif
