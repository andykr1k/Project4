#include "MakeTree.hpp"

MakeTree::MakeTree(){
    _root = nullptr;
}

GraphNode *MakeTree::findHelper( std::string name, TreeNode *root){
    //Base Case
    if (root == nullptr)
        return nullptr;

    //If its the node return
    if (root->graphNode()->getName() == name)
        return root->graphNode();

    //if node is less than find in right
    if (root->graphNode()->getName() < name)
        return findHelper(name, root->right());

    //else find in left
    return findHelper(name, root->left());
}

TreeNode *MakeTree::insert(TreeNode *root, GraphNode *nNode){
    //Base Case
    if ( root == nullptr ){
        return new TreeNode(nNode);
    }

    //if node is less than insert in right
    if (root->graphNode()->getName() < nNode->getName()) {
        root->right(insert(root->right(), nNode));
    } else {
        //else insert in left
        root->left(insert(root->left(), nNode));
    }

    return root;
}

void MakeTree::print(TreeNode *root){
    //Base Case
    if (root == nullptr)
        return;

    //Inorder print left first
    print(root->left());

    //print node
    if ( root->graphNode()->isATarget()){
        root->graphNode()->print();
    }

    //print right last
    print(root->right());
}

void MakeTree::insert( GraphNode *nNode ) {
    //If its not in the tree insert the node
    if (!find(nNode->getName())){
        _root = insert(_root, nNode);
    }
}