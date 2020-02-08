//
//  main.c
//  seqStack
//
//  Created by clockworkSong on 2020/2/8.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//构建顺序栈
typedef struct Stack
{
    int* data;
    int size;
    int top;//栈顶
}st;

void initStack(st* p, int size)
{
    p->size = size;
    p->data = (int*)malloc(sizeof(size));//分配数组大小
    p->top = 0;
}
//数组是否压满
int isFull(const st* p)
{
    return p->top == p->size;
}
//数组是否为空
int isEmpty(const st* p)
{
    return p->top == 0;
}

int pushStack(st* p, int data)
{
    if(isFull(p)) return 0;
    else{
        p->data[p->top] = data;
        p->top ++;
        return 1;
    }
}

int popStack(st* p, int* q)
{
    if(isEmpty(p)) return 0;
    else{
        *q = p->data[p->top-1];
        p->top --;
        return 1;
    }
}

int topStack(const st* p, int* q)
{
    if(isEmpty(p)) return 0;
    else{
        *q = p->data[p->top-1];
        return 1;
    }
}
//销毁
void destroy(st* p)
{
    free(p->data);
}

int main(int argc, const char * argv[]) {

    st t;
    initStack(&t, 5);
    pushStack(&t, 11);
    pushStack(&t, 22);
    pushStack(&t, 33);
    int top = 0;
    popStack(&t, &top);
    popStack(&t, &top);
    printf("pop out = %d\n", top);
    topStack(&t, &top);
    printf("pop = %d\n", top);
    destroy(&t);
    
    return 0;
}
