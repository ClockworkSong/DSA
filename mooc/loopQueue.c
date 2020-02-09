//
//  queue.c
//  cCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//循环队列
typedef struct Queue{
    int* data;
    int size;
    int front;//队首
    int rear;//队尾
}que_t;

void initQueue(que_t* pq, int size)
{
    pq->size = size;
    pq->data = (int*)malloc(sizeof(int)*(size+1));
    pq->front = pq->rear = 0;
}

int isFull(const que_t* pq)
{
    if((pq->rear + 1)%(pq->size+1) == pq->front) return 1;//如果余数为0==front,则队列满了
    else return 0;
}
int isEmpty(const que_t* pq)
{
    return pq->front == pq->rear;//队尾追上对队首，则队列空了
}

int enQueue(que_t* pq, int data)
{
    if(isFull(pq)) return 0;
    else{
        pq->data[pq->rear] = data;
        pq->rear = (pq->rear + 1) % (pq->size + 1);//队尾循环加1
        return 1;
    }
}

int delQueue(que_t* pq, int* px)
{
    if(isEmpty(pq)) return 0;
    else{
        *px = pq->data[pq->front];
        pq->front = (pq->front + 1) % (pq->size + 1);//队首循环加1
        return  1;
    }
}

int main(int argc, const char * argv[]) {
    que_t q;
    initQueue(&q, 5);
    enQueue(&q, 11);
    enQueue(&q, 22);
    enQueue(&q, 33);
    enQueue(&q, 44);
    enQueue(&q, 55);
    enQueue(&q, 66);
    int x;
    delQueue(&q, &x);
    delQueue(&q, &x);
    delQueue(&q, &x);
    delQueue(&q, &x);
    delQueue(&q, &x);
    delQueue(&q, &x);
    printf("x=%d\n", x);
    
    return 0;
}
