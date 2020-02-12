//
//  Tree.c
//  cCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Elem;

typedef struct Heap{
    Elem *data;//空间动态分配
    int capacity;//堆的容量
    int size;//当前堆中元素
    struct BinNode* right;
}*Pheap;


Pheap initHeap(int max){
    Pheap h;
    h = (Pheap)malloc(sizeof(struct Heap));
    if(h == NULL) return NULL;
    h->data = (Elem*)malloc(sizeof(Elem) * (max+1));
    if(h->data == NULL) return NULL;
    h->capacity = max;
    h->size = 0;
    return h;
}

int isFull(Pheap h){
    return h->capacity == h->size;
}

int isEmpty(Pheap h){
    return h->size == 0;
}

//在第k个，元素向上过滤
void filterUp(int k, Pheap h){
    Elem x = h->data[k];
    int i = 0;
    for(i=k; i>1 && h->data[i] < h->data[i/2]; i /= 2){
        h->data[i] = h->data[i/2];//拷贝操作
    }
    h->data[i] = x;
}
//从k位置开始向下过滤
void filterDown(int k, Pheap h){
    Elem x = h->data[k];
    int i=0, child=0;
    for(i=k; i*2 <= h->size; i=child){
        child = i*2;
        //找出比较小的儿子
        if(child != h->size && h->data[child] > h->data[child+1]){
            child ++;
        }
        if(h->data[i] > h->data[child]) {
            h->data[i] = h->data[child];
        }
    }
    h->data[i] = x;
}

int insertHeap(Pheap h, Elem x){
    if(isFull(h)) return 0;
    else{
        h->data[++h->size] = x;//将x放入到顺序表最后一个元素
        filterUp(h->size, h);
        return 1;
    }
}

int removeHeap(Pheap h, Elem* px){
    if(isEmpty(h)) return 0;
    else {
        *px = h->data[1];//堆顶元素
        h->data[1] = h->data[h->size--];//最后元素拿来代替堆顶
        filterDown(1, h);
        return 1;
    }
}

void printHeap(Pheap h){
    for(int i=1; i <= h->size; i++)
        printf("%d ", h->data[i]);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    Pheap h = initHeap(10);
    insertHeap(h, 20);
    insertHeap(h, 10);
    insertHeap(h, 5);
    insertHeap(h, 15);
    insertHeap(h, 30);
    insertHeap(h, 18);
    printHeap(h);
    Elem x;
    removeHeap(h, &x);
    printf("x=%d\n", x);
    printHeap(h);
    return 0;
}
