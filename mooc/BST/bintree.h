//
//  binTree.h
//  cppCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

/*
 Description:
*/

#ifndef bintree_h
#define bintree_h

#include <iostream>
#include <stack>

using namespace std;
template<class Elem>

//链式二叉树结构体
struct BinNode{
    Elem data;
    BinNode<Elem>* left;
    BinNode<Elem>* right;
    BinNode(Elem x){//用参数x来构造函数
        data = x;
        left = right = NULL;
    }
};
//二叉树类
template<class Elem> //使用类的模板来写一个二叉树
class BinTree{
protected:
    BinNode<Elem> *root;//根节点指针
    void callPreOrder(BinNode<Elem>* r);
    void callInOrder(BinNode<Elem>* r);
    void callPostOrder(BinNode<Elem>* r);
    int callCount(BinNode<Elem>* r);
    BinNode<Elem>* callFindX(Elem x, BinNode<Elem> *r);
public:
    BinTree(){ root = NULL; }//无参构造
    BinTree(Elem r)//带参数构造完成初始化
    {
        root = new BinNode<Elem>(r);
    }
    ~BinTree(){/*TODO*/}
    //前序遍历
    void preOrder(){
        callPreOrder(root);
        cout << endl;
    }
    //中序遍历
    void inOrder(){
        callInOrder(root);
        cout << endl;
    }
    //后遍历
    void postOrder(){
        callPostOrder(root);
        cout << endl;
    }
    BinNode<Elem>* findX(Elem x){
        return callFindX(x, root);
    }
    bool insertNode(Elem r, int lr, Elem x){
        BinNode<Elem> *f = findX(r);
        if(f == NULL) return false;
        if(lr == 0){//选择左子树插入
            if(f->left != NULL) return false;//插入位置不为空则插入失败
            f->left = new BinNode<Elem>(x);
        }
        else{//选择右子树插入
            if(f->right != NULL) return false;//插入位置不为空则插入失败
            f->right = new BinNode<Elem>(x);
        }
        return true;
    }
    void print(){
        callPrint(root, 0);//从树根，深度为0开始打印
    }
    int count(){
        return callCount(root);
    }
};

//成员函数的定义如下，这些函数依然是类的成员函数的模板
template <class Elem>//类的模板
void BinTree<Elem>::callPreOrder(BinNode<Elem>* r){
    if(r == NULL) return;//凡是指针都有可能为空
    cout << r->data << ' ';
    callPreOrder(r->left);
    callPreOrder(r->right);
}
template <class Elem>
void BinTree<Elem>::callInOrder(BinNode<Elem>* r){
    if(r == NULL) return;//凡是指针都有可能为空
    callInOrder(r->left);
    cout << r->data << ' ';
    callInOrder(r->right);
}
template <class Elem>
void BinTree<Elem>::callPostOrder(BinNode<Elem>* r){
    if(r == NULL) return;//凡是指针都有可能为空
    callPostOrder(r->left);
    callPostOrder(r->right);
    cout << r->data << ' ';
}
template <class Elem>
int BinTree<Elem>::callCount(BinNode<Elem>* r){
    if(r == NULL) return 0;
    if(r->left == NULL && r->right == NULL) return 1;
    return callCount(r->left) + callCount(r->right);
}
template <class Elem>
BinNode<Elem>* BinTree<Elem>::callFindX(Elem x, BinNode<Elem> *r){
    if(r == NULL) return NULL;
    if(r->data == x) return r;
    BinNode<Elem> *f;
    f = callFindX(x, r->left);
    return f ? f : callFindX(x, r->right);
}

#endif
