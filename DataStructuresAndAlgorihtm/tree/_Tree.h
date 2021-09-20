/*
 * Created by weyiua on 2021/9/5.
 * Tree
 * Binary Tree ����insert delete ?
 *
 * �� ������ ���������� AVL�� B��
 */

#ifndef _TREE_H
#define _TREE_H

#include <deque>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <functional>
using std::deque;
using std::cout;

#define null static_cast<Postion>(nullptr)
const int NULLNODE = 0x3fffffff;

struct TreeNode;
typedef TreeNode* Postion;

struct TreeNode {
    int _value;
    Postion _left;
    Postion _right;

    TreeNode(int value) : _value(value), _left(null), _right(null) {}
};

class Tree {
public:
    Tree() : _root(null), _treeLen(0) {}

    Tree(int* p, int len) {
        _treeLen = len;
        _root = new TreeNode(*p++);
        deque<Postion> ideq;
        ideq.push_back(_root);
        for(int i = 1; i < len; i += 2) {
            Postion t = ideq.front();
            ideq.pop_front();
            if(i < len) t->_left = *p == NULLNODE ? null : new TreeNode(*p);
            ++p;
            if(i + 1 < len) t->_right = *p == NULLNODE ? null : new TreeNode(*p);
            ++p;
            if(t->_left) ideq.push_back(t->_left);
            if(t->_right) ideq.push_back(t->_right);
        }
    }

    ~Tree() { destryTree(_root); }

    Postion getTree() const {
        return _root;
    }

    bool destryTree(Postion postion) {
        if(postion == null) return false;
        Postion temp = postion;
        destryTree(temp->_left);
        destryTree(temp->_right);
        delete temp;
        _treeLen = 0;
        return true;
    }

    void setLeft(int value) {
        if(_root && _root->_left == null) _root->_left = new TreeNode(value);
    }

    void setRight(int value) {
        if(_root && _root->_right == null) _root->_right = new TreeNode(value);
    }

    //�������
    void firstSequenceTraversalTree() {
        cout << "firstSequenceTraversalTree : \n";
        std::function<void(Postion)> func = [&](Postion root) {
            if(root) {
                cout << root->_value << " ";
                func(root->_left);
                func(root->_right);
            }
        };
        func(_root);
        cout << std::endl;
    }

    //�������
    void inOrderTraversalTree() {
        cout << "inOrderTraversalTree : \n";
        std::function<void(Postion)> func = [&](Postion root) {
            if(root) {
                func(root->_left);
                cout << root->_value << " ";
                func(root->_right);
            }

        };
        func(_root);
        cout << std::endl;
    }

    //��������
    void subsequentTraversalTree() {
        cout << "subsequentTraversalTree : \n";
        std::function<void(Postion)> func = [&](Postion root) {
            if(root) {
                func(root->_left);
                func(root->_right);
                cout << root->_value << " ";
            }
        };
        func(_root);
        cout << std::endl;
    }

    //�������
    void sequenceTraversal() {
        cout << "sequenceTraversal : \n";
        if(_root == null) return ;
        deque<Postion> ideque;
        ideque.push_back(_root);
        while(!ideque.empty()) {
            int len = ideque.size();
            for(int i = 0; i < len; ++i) {
                Postion t = ideque.front();
                ideque.pop_front();
                cout << t->_value << " ";
                if(t->_left) ideque.push_back(t->_left);
                if(t->_right) ideque.push_back(t->_right);
            }
            cout << std::endl;
        }
    }

private:
    Postion _root;
    int _treeLen;
};

//��ȡ������ �����ĸ߶�
int getTreeHepth(Postion root) {
    if(root) {
        return 1 + std::max(getTreeHepth(root->_left), getTreeHepth(root->_right));
    }
    return 0;
}
struct BinaryTreeNode;

#define nullBin static_cast<BinaryPostion>(nullptr)
typedef BinaryTreeNode* BinaryPostion;

struct BinaryTreeNode  {
    int _value;
    int _count;     //����insert delete ? ͳ�Ƹ���
    BinaryPostion _left;
    BinaryPostion _right;
    BinaryTreeNode() : _value(NULLNODE), _count(0), _left(nullBin), _right(nullBin) {}
    BinaryTreeNode(int value) : _value(value), _count(1), _left(nullBin), _right(nullBin) {}
};

//��������� �������Ӧ������
class BinaryTree {
public:
    BinaryTree() : _root(nullBin) {}

    ~BinaryTree() {
        destryTree(_root);
    }

    bool destryTree(BinaryPostion postion) {
        if(postion == nullBin) return false;
        BinaryPostion temp = postion;
        destryTree(temp->_left);
        destryTree(temp->_right);
        delete temp;
        return true;
    }

    BinaryPostion findBinartTree(BinaryPostion postion, int value) {
        while(postion) {
            if(postion->_value == value) return postion;
            else if(postion->_value > value) postion = postion->_left;
            else postion = postion->_right;
        }
        return postion;
    }

    BinaryPostion insert(BinaryPostion& post, int value) {
        if(post == nullBin) {
            post = new BinaryTreeNode(value);
        } else {
            if(post->_value > value) {
                post->_left = insert(post->_left, value);
            } else if(post->_value < value) {
                post->_right = insert(post->_right, value);
            }
        }
        return post;
    };


    //����ڵ�
    bool insertBinaryTree(int value) {
        BinaryPostion postion = findBinartTree(_root, value);
        //����insert
        if(postion != nullBin) {
            ++postion->_count;
        } else {
            insert(_root, value);
        }
        return true;
    }

    //?
    bool isNoDeletToisCount(BinaryPostion postion, int value) {
        BinaryPostion post = findBinartTree(postion, value);
        if(post == nullBin) return false;
        if(post->_value > 1) {
            --post->_count;
        }
        return false;
    }


    //ɾ���ڵ�
    BinaryPostion deleteBinary(BinaryPostion postion, int value) {
        //�������������
        // 1.ΪҶ��  2.ֻ��һ������  3.��ǰ�������������
        if(postion == nullBin) {
            return postion;
        } else {
            BinaryPostion temp = nullBin;
            if(postion->_value > value) {
                postion->_left = deleteBinary(postion->_left, value);
            } else if(postion->_value < value) {
                postion->_right = deleteBinary(postion->_right, value);
            } else {
                //�ҵ�ɾ��Ԫ��
                if(postion->_left && postion->_right){
                    //��ǰ�ڵ���������
                    //Ѱ���Һ��� �� ��С�Ľ�� ����Ԫ�� ɾ����С���
                    temp = findMinBinaryTree(postion->_right);
                    postion->_value = temp->_value;
                    postion->_right = deleteBinary(postion->_right, postion->_value);
                } else {
                    //��ǰ�ڵ�ΪҶ�ӽڵ����ֻ��һ������
                    temp = postion;
                    if(postion->_left == nullBin) {
                        postion = postion->_right;
                    } else if(postion->_right ==nullBin) {
                        postion = postion->_left;
                    }
                    //ɾ��Ҷ�Ӻ͵����ӵĽ��
                    delete temp;
                }
            }
        }
        return postion;
    }

    bool deleteBinaryTree(int value) {
        if(findBinartTree(_root, value) == nullBin) return false;
        _root = deleteBinary(_root, value);
        return true;
    }

    BinaryPostion findMinBinaryTree(BinaryPostion postion) {
        if(postion == nullBin) return nullBin;
        while(postion) {
            if(!postion->_left && !postion->_right) return postion;
            postion = postion->_left ? postion->_left : postion->_right;
        }
        return nullBin;
    }

    //�������
    void inOrderTraversalBinaryTree() {
        if(_root == nullBin) cout << "Binary Tree is null\n";
        std::function<void(BinaryPostion&)> LRRToTracersal = [&](BinaryPostion& postion) {
            if(postion != nullBin) {
                LRRToTracersal(postion->_left);
                cout << "value : " << postion->_value << " count: " << postion->_count << "\n";
                LRRToTracersal(postion->_right);
            }
        };
        LRRToTracersal(_root);
        cout << "inOrderTraversalBinaryTree end\n";
    }

    BinaryPostion getBinaryTree() const {
        return _root;
    }

    void setBinaryTree(BinaryPostion postion) {
        _root = postion;
    }

private:
    BinaryPostion _root;
};


#endif //_TREE_H