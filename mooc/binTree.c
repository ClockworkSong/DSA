//
//  Tree.c
//  cCode
//
//  Created by clockworkSong on 2020/2/9.
//  Copyright © 2020 clockworkSong. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct BinNode{
    int data;
    struct BinNode* left;
    struct BinNode* right;
}*pBinTree;

pBinTree initBinTree(int x){
    pBinTree b;
    b = (pBinTree)malloc(sizeof(struct BinNode));
    b->data = x;
    b->left = b->right = NULL;
    return b;
}

//前序遍历
void preOrder(const pBinTree p)
{
    if(p == NULL) return;
    printf("%d ", p->data);
    preOrder(p->left);
    preOrder(p->right);
}

pBinTree findX(pBinTree r, int x){
    if(r == NULL) return NULL;
    if(r->data == x) return r;
    pBinTree f = findX(r->left, x);
    return f ? f : findX(r->right, x);
}

int insertBinTree(pBinTree pb, int rdata, int lr, int data){
    pBinTree f = findX(pb, rdata);
    if(f == NULL) return 0;
    if(lr == 0){
        if(f->left != NULL) return 0;
        f->left = initBinTree(data);
    }
    else{
        if(f->right != NULL) return 0;
        f->right = initBinTree(data);
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    pBinTree t = initBinTree(11);
    insertBinTree(t, 11, 0, 22);
    insertBinTree(t, 11, 1, 33);
    insertBinTree(t, 22, 0, 44);
    insertBinTree(t, 33, 0, 55);
    preOrder(t);
    printf("\n");

    return 0;
}
