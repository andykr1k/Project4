#include "TreeNode.hpp"

TreeNode::TreeNode( GraphNode *nNode ) {
    makeNode = nNode;
    leftSubtree = nullptr;
    rightSubtree = nullptr;
}