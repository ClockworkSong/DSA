//
//  main.cpp
//  cppCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

/*
Description:实现二叉搜索树
*/

#include <iostream>
#include "bintree.h"

using namespace std;
template<class Elem>

//新模板继承于BinTree
class BSTree:public BinTree<Elem>{
protected:
    BinNode<Elem>* callFindMax(BinNode<Elem>* r){
        if(r->right == NULL) return r;
        return callFindMax(r->right);//尾递归
    }
    BinNode<Elem>* callFindMin(BinNode<Elem>* r){
        if(r->left == NULL) return r;
        return callFindMax(r->left);//尾递归
    }
    BinNode<Elem>* callInsertTar(Elem x, BinNode<Elem>* r){
        if(r == NULL){
            r = new BinNode<Elem>(x);
            if(r == NULL) throw -1;
        }
        else if(x < r->data){
            r->left = callInsertTar(x, r->left);
        }
        else if (x > r->data){
            r->right = callInsertTar(x, r->right);
        }
        else{//插入元素已存在
            throw -2;
        }
        return r;
    }
    BinNode<Elem>* callRemoveTar(Elem x, BinNode<Elem>* r){
        BinNode<Elem>* tmp;
        if(r == NULL) throw -1;//删除失败
        else if(x < r->data){
            r->left = callRemoveTar(x, r->left);
        }
        else if(x > r->data){
            r->right = callRemoveTar(x, r->right);
        }
        else{//x=r->data
            if(r->left != NULL && r->right != NULL){//包含左子树和右子树
                tmp = callFindMax(r->left);
                r->data = tmp->data;
                r->left = callRemoveTar(tmp->data, r->left);
            }
            else{//左空、右空和全空一样
                tmp = r;
                r = r->left ? r->left : r->right;
                delete tmp;
            }
        }
        return r;//返回删除以后的树根
    }
public:
    BSTree(){//无参构造
        this->root = NULL;
    }
    BinNode<Elem>* findMax(){//返回找到节点地址
//        return callFindMax(this->root);
        BinNode<Elem>* tmp = this->root;
        while (tmp != NULL && tmp->right != NULL) {//一路向右
            tmp = tmp->right;
        }
        return tmp;
    }
    BinNode<Elem>* findMin(){//返回找到节点地址
        return callFindMin(this->root);
//        BinNode<Elem>* tmp = this->root;
//        while (tmp != NULL && tmp->left != NULL) {//一路向左
//            tmp = tmp->left;
//        }
    }
    BinNode<Elem>* findTar(Elem x){
        BinNode<Elem>* tmp = this->root;
        while( tmp != NULL && x != tmp->data){
            if(x < tmp->data) tmp = tmp->left;
            else tmp = tmp->right;
        }
        return tmp;
    }
    bool insertTar(Elem x){
        try{
            this->root = callInsertTar(x, this->root);
        }
        catch(int e){
            return false;
        }
        return true;
    }
    bool removeTar(Elem x){
        try{
            this->root = callRemoveTar(x, this->root);
        }
        catch(int e){
            return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    BSTree<int> bt;
    cout << bt.findMax() << endl;
    bt.insertTar(10);
    bt.insertTar(5);
    bt.insertTar(20);
    bt.insertTar(8);
    bt.insertTar(15);
    bt.insertTar(2);
    bt.insertTar(6);
    bt.preOrder();
    cout << bt.findMax()->data << endl;
    cout << bt.findMin()->data << endl;
    cout << bt.findTar(66) << endl;
    bt.removeTar(10);
    bt.preOrder();
    
    return 0;
}
