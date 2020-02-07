/*************************************************************************
	> File Name: 08binary_search_tree.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Tue Feb  4 16:49:03 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tree
{
	int data;
	struct Tree* lchild;
	struct Tree* rchild;
}tree_t, *ptree;

//二叉排序树查找算法
bool searchBST(ptree t, int data, ptree f, ptree* p)
{
	//如果t指针为空，说明查找失败，令p指针指向查找过程中最后一个叶子节点，并返回查找失败的信息
	if(t == NULL)
	{
		*p = f;
		printf("failed!\n");
		return false;
	}
	else if (data == t->data)//如果相等，令p指针指向该关键字，并返回查找成功信息
	{
		*p = t;
		printf("succeed!\n");
		return true;
	}
	else if(data < t->data)//data比t根节点的值小，则查找其左子树
	{
		return searchBST(t->lchild, data, t, p);
	}
	else
	{
		return searchBST(t->rchild, data, t, p);
	}
}

//插入数据
bool insertBST(ptree* t, int data)
{
	ptree p = NULL;
	//如果查找不成功，需要做插入操作
	if(!searchBST((*t), data, NULL, &p))
	{
		//初始化插入节点
		ptree q = (ptree)malloc(sizeof(struct Tree));
		if(q == NULL) exit(-1);
		q->data = data;
		q->lchild = NULL;
		q->rchild = NULL;
		//如果p为NULL说明该二叉排序树为空，次时插入的节点为整棵树的根节点
		if(p == NULL)
		{
			printf("root\n");
			*t = q;
		}
		else if(data < p->data)//p指向查找失败的最后一个叶子节点
		{
			printf("ldata =%d\n", data);
			p->lchild = q;

		}
		else
		{
			printf("rdata =%d\n", data);
			p->rchild = q;
		}
		return true;
	}
	else//如果查找成功，不做插入操作，插入失败
	{
		printf("查找成功！\n");
		return false;
	}
}

//删除函数
void Delete(ptree* p)
{
    ptree q,s;
    if((*p)->rchild==NULL)//右子树空则只需重接它的左子树
    {
        q=*p;*p=(*p)->lchild;free(q);
    }
    else if((*p)->lchild==NULL)//只需重接它的右子树
    {
        q=*p;*p=(*p)->rchild;free(q);
    }
    else//左右子树都不空
    {
        q=*p;s=(*p)->lchild;
        while(s->rchild){//转左，然后向右到尽头
            q=s;s=s->rchild;
        
        }
        (*p)->data=s->data;//s指向被删结点的直接前驱
        if(q!=*p)
            q->rchild=s->lchild;//重接q的右子树
        else
            q->lchild=s->lchild;//重接q的左子树
        free(s);
    }
    return;
}


//删除元素
bool deleteBST(ptree* t, int key)
{
	if((*t) == NULL) return false;
	if (key == (*t)->data)
	{
		printf("del = %d\n", key);
		Delete(t);
		return true;
	}
	else if(key < (*t)->data)
	{
		return deleteBST(&(*t)->lchild, key);
	}
	else
	{
		return deleteBST(&(*t)->rchild, key);
	}
}

void order(ptree t)
{
	if(t != NULL)
	{
		order(t->lchild);
		printf("%d ", t->data);
		order(t->rchild);
	}
	return;
}

void inOrder(ptree t)
{
	if(t == NULL) return;
	inOrder(t->lchild);
	printf("%d ", t->data);
	inOrder(t->rchild);
}

int main()
{
	int arr[5] = {3, 4, 2, 5, 9};
	
	//tree_t* t = initTree(arr);
	ptree t = NULL;
	for(int i = 0; i < 5; i ++)
	{
		insertBST(&t, arr[i]);
		printf("i=%d\n", i);
	}
	printf("中序遍历二叉排序树:\n");
	order(t);
	printf("\n");
	printf("删除3后，中序遍历二叉排序树:\n");
	deleteBST(&t, 3);
	order(t);
	printf("\n");
	return 0;
}

