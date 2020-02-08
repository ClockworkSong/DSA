//
//  main.c
//  linkList
//
//  Created by clockworkSong on 2020/2/8.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}node_t, *node_p;

//head是指针，传递的是地址，所以用指针的指针来承接
void initList(node_t** phead)
{
    *phead = NULL;
}

int getLength(node_t* head)
{
    int len = 0;
    while(head)
    {
        len ++;
        head = head->next;
    }
    return len;
}
node_t* findElem(node_t* head, int k)
{
    int count = 1;
    node_t* p = head;
    while (p && count < k) {
        p = p->next;
        count ++;
    }
    return p;
}

void printList(node_t* head)
{
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

node_t* createNode(int data)
{
    node_t* q = (node_t*)malloc(sizeof(struct Node));
    if(q == NULL) exit(-1);
    q->next = NULL;
    q->data = data;
    return q;
}

int insertList(node_t** phead, int k, int elem)
{
    if(k < 1)
    {
        return 0;
    }
    else if(k == 1)//第一个节点插入的时候特殊操作
    {
        node_t* t = createNode(elem);
        t->next = *phead;
        *phead = t;
        return 1;
    }
    else
    {
        node_t* p;//指向k-1的位置
        /*int count = 1;
        p = *phead;//初始化
        while(p != NULL && count < k-1)
        {
            p = p->next;
            count ++;
        }*/
        p = findElem(*phead, k-1);
        if(p)
        {
            node_t* t = createNode(elem);
            t->next = p->next;
            p->next = t;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int deleteList(node_t** phead, int k, int* pe)
{
    if(k < 1)
    {
        return 0;
    }
    else if(k == 1)
    {
        if(*phead != NULL)
        {
            *pe = (*phead)->data;
            *phead = (*phead)->next;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        node_t* p = findElem(*phead, k-1);
        if(p == NULL || p->next == NULL) return 0;
        node_t* t = p->next;
        p->next = t->next;
        *pe = t->data;
        free(t);
        return 1;
    }
}

int main(int argc, const char * argv[]) {
    node_t* head;
    initList(&head);//修改函数，所以传递指针
    //int len = getLength(head);//值传递，不会修改函数head
    //printf("len = %d\n", len);
    insertList(&head, 1, 11);
    insertList(&head, 1, 22);
    insertList(&head, 2, 33);
    insertList(&head, 3, 44);
    insertList(&head, 4, 55);
    printList(head);
    int elem = 0;
    deleteList(&head, 1, &elem);
    printf("delete elem = %d\n", elem);
    printList(head);
    deleteList(&head, 4, &elem);
    printf("delete elem = %d\n", elem);
    printList(head);
    deleteList(&head, 2, &elem);
    printf("delete elem = %d\n", elem);
    printList(head);
    
    return 0;
}

