//
//  linkQueue.cpp
//  cppCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x)//构造函数
    {
        data = x;
        next = NULL;
    }
};

class Queue
{
private:
    Node* front;
    Node* rear;
public:
    Queue()//构造函数
    {
        front = rear = NULL;
    }
    ~Queue()//析构函数
    {
        Node* tmp;
        while (front != NULL) {
            tmp = front;
            front = front->next;
            delete tmp;
        }
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    void enQueue(int x)//成员函数本身含有this
    {
        Node *tmp;
        tmp = new Node(x);//创建新节点,初始化为Node节点的构造函数
        if(isEmpty()){
            front = rear = tmp;//两个指针都指向创建节点
        }
        else{
            rear->next = tmp;//指向新插入节点地址
            rear = rear->next;
        }
    }
    bool delQueue(int* pdata)
    {
        if(isEmpty()) return false;
        else{
            *pdata = front->data;//获取出队元素
            Node* tmp = front;
            front = front->next;
            delete tmp;//释放出队节点内存
            if(front == NULL) rear = NULL;//判断出队后队列是否为空
            return true;
        }
    }
};

int main(int argc, const char * argv[]) {
    Queue q;
    q.enQueue(11);
    q.enQueue(22);
    q.enQueue(33);
    q.enQueue(44);
    int x;
    q.delQueue(&x);
    cout << x << endl;
    q.delQueue(&x);
    cout << x << endl;
    q.delQueue(&x);
    cout << x << endl;
    q.delQueue(&x);
    cout << x << endl;
    
    return 0;
}
