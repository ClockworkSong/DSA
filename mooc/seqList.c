//
//  main.c
//  table
//
//  Created by clockworkSong on 2020/2/8.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <stdio.h>

#define MAX 10

typedef struct Slist{
    int arr[MAX];
    int length;//元素个数
}list_t;

void initList(list_t* p)
{
    p->length = 0;
}

void printList(const list_t* p)
{
    for(int i=0; i<p->length; i++)
    {
        printf("%d ", p->arr[i]);
    }
    printf("\n");
}
//返回插入后的结果
int insertList(list_t* p, int index, int data)
{
    if(index < 0 || index > p->length || p->length == MAX-1) return 0;
    else
    {
        for(int i=p->length-1; i>=index; i--)
        {
            p->arr[i+1] = p->arr[i];//整体后移一位
        }
        p->arr[index] = data;//对插入的位置进行赋值
        p->length ++;
        return 1;
    }
}

int deleteList(list_t* p, int index, int* q)
{
    if(index < 0 || index >= p->length) return 0;
    else
    {
        *q = p->arr[index];
        for(int i=index+1; i < p->length; i++)
        {
            p->arr[i-1] = p->arr[i];//整体前移一位
        }
        p->length --;
        return 1;
    }
}

int main(int argc, const char * argv[]) {
    list_t t;
    initList(&t);
    int index = 0, data = 11;
    insertList(&t, index, data);
    insertList(&t, index, data+1);
    insertList(&t, index+1, data+2);
    printList(&t);
    int elem = 0;
    deleteList(&t, index, &elem);
    printf("delete elem=%d\n", elem);
    printList(&t);
    
    return 0;
}
