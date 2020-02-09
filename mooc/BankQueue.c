//
//  BankQueue.c
//  cCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/*
 Input sample:
 
 3
 In 101
 In 102
 In 103
 In 104
 Calling
 In 105
 Calling
 Calling
 Calling
 Calling
 #
 
 */

//循环队列
typedef struct Queue{
    int* data;
    int size;//大小
    int front;//队首
    int rear;//队尾
    int number;//人数
}que_t;

void initQueue(que_t* pq, int size)
{
    pq->size = size;
    pq->data = (int*)malloc(sizeof(int)*(size+1));
    pq->front = pq->rear = pq->number = 0;
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
        pq->number ++;
        return 1;
    }
}

int delQueue(que_t* pq, int* px)
{
    if(isEmpty(pq)) return 0;
    else{
        *px = pq->data[pq->front];
        pq->front = (pq->front + 1) % (pq->size + 1);//队首循环加1
        pq->number --;
        return  1;
    }
}

int main(int argc, const char * argv[]) {
    int N;
    scanf("%d", &N);
    que_t q;
    initQueue(&q, N);
    char op[20];
    int id;
    scanf("%s", op);
    while (op[0] != '#') {
        if(op[0] == 'I'){//有人加入
            scanf("%d", &id);
            if(isFull(&q)){
                printf("<%d> rejected.\n", id);
            }
            else{
                enQueue(&q, id);//入队
                printf("<%d> joined. Total:<%d>\n", id, q.number);
            }
        }
        else{//叫号
            if(isEmpty(&q)){
                printf("No one!\n");
            }
            else{
                delQueue(&q, &id);
                printf("<%d> called. Total:<%d>\n", id, q.number);
            }
        }
        scanf("%s", op);
    }

    return 0;
}
