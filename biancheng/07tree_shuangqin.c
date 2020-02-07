/*************************************************************************
	> File Name: 07tree_shuangqin.c
	> Author: clockworkSong
	> mail: ggdong5515@gmail.com
	> Created Time: Sun Feb  2 09:47:42 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
//节点结构
typedef struct Node
{
	char data;
	int parent;
}node_t;
//树结构
typedef struct Tree
{
	node_t arr[SIZE];
	int num;//节点个数
}tree_t;

tree_t initTree(tree_t t)
{
	/*printf("请输入节点个数:");
	scanf("%d", &(t.num));
	char ch;
	int j = 0;
	printf("请输入节点的值和其双亲位于数组中的位置下标:\n");
	for(int i = 0; i<t.num; i ++)
	{
		fflush(stdin);
		scanf("%c", &ch);
		printf("c=%ch\n",ch);
		scanf("%d", &j);
		printf("j=%d\n",j);
		t.arr[i].data = ch;
		t.arr[i].parent = j;
	}*/
	t.num = 10;
	t.arr[0].data = 'R';
	t.arr[0].parent = -1;
	t.arr[1].data = 'A';
	t.arr[1].parent = 0;
	t.arr[2].data = 'B';
	t.arr[2].parent = 0;
	t.arr[3].data = 'C';
	t.arr[3].parent = 0;
	t.arr[4].data = 'D';
	t.arr[4].parent = 1;
	t.arr[5].data = 'E';
	t.arr[5].parent = 1;
	t.arr[6].data = 'F';
	t.arr[6].parent = 3;
	t.arr[7].data = 'G';
	t.arr[7].parent = 6;
	t.arr[8].data = 'H';
	t.arr[8].parent = 6;
	t.arr[9].data = 'K';
	t.arr[9].parent = 6;

	return t;
}

void findParent(tree_t t)
{
	char ch;
	int isFind = 0;
	printf("请输入要查询的节点值:\n");
	//fflush(stdin);
	scanf("%c", &ch);
	for(int i = 0; i < t.num; i++)
	{
		if(t.arr[i].data == ch)
		{
			isFind = 1;
			int p = t.arr[i].parent;
			printf("%c的父节点为%c，存储位置下标为%d\n", ch, t.arr[p].data, p);
			break;
		}
	}
	if(isFind == 0) printf("查无此节点!\n");
}

int main()
{
	tree_t t;
	t = initTree(t);
	findParent(t);
	return 0;
}
