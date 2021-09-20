/*
 * Created by weyiua on 2021/9/5.
 */

#include "_Tree.h"
#include <iostream>
using namespace std;

void testTree() {
    int ivec[12] = {1,2,3,4,5,6,NULLNODE, NULLNODE, 7,8,9,10};
    Tree tree(ivec, 12);
    tree.sequenceTraversal();
    tree.firstSequenceTraversalTree();
    tree.inOrderTraversalTree();
    tree.subsequentTraversalTree();

    cout << getTreeHepth(tree.getTree()) << endl;
}

void binaryTreeTest() {
    BinaryTree binaryTree;
    int ivec[] = {23,3,4,13,5,4,1,23,3,4,5,67,7,7,8,6,4,34,2,21,23,124,32,5,34,4,6,45};
    //int ivec[] = {3,2,4};
    binaryTree.insertBinaryTree(1);
    binaryTree.inOrderTraversalBinaryTree();
    binaryTree.deleteBinaryTree(1);
    binaryTree.inOrderTraversalBinaryTree();

    for(int i : ivec) {
        binaryTree.insertBinaryTree(i);
    }

    binaryTree.inOrderTraversalBinaryTree();

    for(int i : ivec) binaryTree.deleteBinaryTree(i);
    binaryTree.inOrderTraversalBinaryTree();
}

int main(int agrc, const char* agrv[]) {
    //testTree();
    binaryTreeTest();
    return 0;
}