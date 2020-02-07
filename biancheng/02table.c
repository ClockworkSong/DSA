#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5//对size进行宏定义，表示顺序表申请空间大小

typedef struct Table
{
	int arr[SIZE];//声明一个数组，大小为SIZE
	int len;//记录当前顺序表的长度
}table;

//初始化顺序表
table initTable()
{
	table t;
	memset(t.arr, 0, sizeof(t.arr));
	t.len = 0;//空表的长度初始化为0
	return t;
}

//遍历顺序表
void displayTable(table t)
{
	for(int i=0; i < t.len; i++)
	{
		printf("%d ", t.arr[i]);
	}
	printf("\n");
}

//顺序表插入元素，其中elem为插入元素，pos为插入到顺序表的位置
table addTable(table t, int elem, int pos)
{
	//判断插入本身是否存在问题
	if(pos > t.len+1 || pos < 1) 
	{
		printf("插入位置有问题!\n");
		return t;
	}
	if(t.len >= SIZE)
	{	
		printf("插入[%d, %d]失败，超过数组SIZE长度!\n", elem, pos);
		return t;
	}
	for(int i = t.len-1;i >= pos-1; i-- )
	{
		t.arr[i+1] = t.arr[i];
	}
	t.arr[pos-1] = elem;
	t.len ++;
	return t;
}

//顺序表查找元素
int selectTable(table t, int elem)
{
	for(int i = 0;i < t.len; i++)
	{
		if(elem == t.arr[i])
			return i+1;
	}
	return -1;//如果查找失败，返回-1
}

//顺序表更改元素
table ammendTable(table t, int pos, int elem)
{
	t.arr[pos-1] = elem;
	return t;
}

//顺序表删除元素
table delTable(table t, int pos)
{
	//判断插入本身是否存在问题
	if(pos > t.len+1 || pos < 1) 
	{
		printf("删除的位置有问题!\n");
		return t;
	}
	for(int i = pos;i <= t.len; i++ )
	{
		t.arr[i-1] = t.arr[i];
	}
	t.len --;
	return t;
}

int main()
{
	table t = initTable();
	displayTable(t);
	t = addTable(t, 10, 1);
	t = addTable(t, 10, 1);
	t = addTable(t, 20, 2);
	t = addTable(t, 20, 2);
	t = addTable(t, 30, 2);
	t = addTable(t, 30, 2);
	displayTable(t);
	printf("pos = %d\n", selectTable(t, 30));
	t = delTable(t, 2);
	displayTable(t);
	t = ammendTable(t, 2, 255);
	displayTable(t);

	return 0;
}
