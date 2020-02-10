//
//  binTree.cpp
//  cppCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

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
    //内部方法，不对外提供
    void callPreOrder(BinNode<Elem>* r){
        if(r == NULL) return;//凡是指针都有可能为空
        cout << r->data << ' ';
        callPreOrder(r->left);
        callPreOrder(r->right);
    }
    void itPreOrder(BinNode<Elem>* r){//迭代方法代替递归
        stack<BinNode<Elem>*> st;//将节点的地址压入栈中
        if(r == NULL) return;
        while(r){
            cout << r->data << " ";
            st.push(r);//压栈
            r = r->left;
            while(r == NULL && !st.empty()){//左or右子树遍历完,栈是否为空
                r = st.top();//栈顶元素
                st.pop();//出栈
                r = r->right;//后撤步
            }
        }
    }
    void callInOrder(BinNode<Elem>* r){
        if(r == NULL) return;//凡是指针都有可能为空
        callInOrder(r->left);
        cout << r->data << ' ';
        callInOrder(r->right);
    }
    void itInOrder(BinNode<Elem>* r){//迭代方法代替递归
        stack<BinNode<Elem>*> st;//将节点的地址压入栈中
        if(r == NULL) return;
        while(r){
            st.push(r);//压栈
            r = r->left;
            while(r == NULL && !st.empty()){//左or右子树遍历完,栈是否为空
                r = st.top();//栈顶元素
                st.pop();//出栈
                cout << r->data << " ";
                r = r->right;//后撤步
            }
        }
    }
    void callPostOrder(BinNode<Elem>* r){
        if(r == NULL) return;//凡是指针都有可能为空
        callPostOrder(r->left);
        callPostOrder(r->right);
        cout << r->data << ' ';
    }
    BinNode<Elem>* callFindX(Elem x, BinNode<Elem> *r){
        if(r == NULL) return NULL;
        if(r->data == x) return r;
        BinNode<Elem> *f;
        f = callFindX(x, r->left);
        return f ? f : callFindX(x, r->right);
    }
    void callPrint(BinNode<Elem>* r, int depth){
        for(int i=0; i<depth; i++)
            cout << "  ";
        if(!r){//如果为空地址打印[/]
            cout << "[/]" << endl;
        }
        else{
            cout << r->data << endl;
            callPrint(r->left, depth+1);
            callPrint(r->right, depth+1);
        }
    }
public:
    BinTree(){ root = NULL; }
    BinTree(Elem r)//带参数构造完成初始化
    {
        root = new BinNode<Elem>(r);
    }
    ~BinTree(){/*TODO*/}
    //前序遍历
    void preOrder(){
        //callPreOrder(root);
        itPreOrder(root);
        cout << endl;
    }
    //中序遍历
    void inOrder(){
        //callInOrder(root);
        itInOrder(root);
        cout << endl;
    }
    //中序遍历
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
};

int main(int argc, const char * argv[]) {
    BinTree<int> bt(11);//以11为树根构造二叉树
    bt.insertNode(11, 0, 22);
    bt.insertNode(11, 1, 33);
    bt.insertNode(22, 0, 44);
    bt.insertNode(33, 0, 55);
    bt.preOrder();//面向对象的编程思想
    bt.inOrder();
    bt.postOrder();
//    bt.print();
    
    return 0;
}
