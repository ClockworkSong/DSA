#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define SIZE 10
typedef int DataType;///将int类型重定义

//采用数组来描述顺序表
typedef struct SeqList
{
	DataType list[SIZE];
	int length;
}list_t;

//初始化线性表
void initList(list_t* p)
{
	assert(p != NULL);//空指针检查
	p->length = 0;//把线性表的长度设置为0
	memset(p->list, 0, sizeof(p->list));//使用memset函数进行初始化
}

//线性表数据遍历
void printList(list_t *p)
{
	assert(p != NULL);//空指针检查
	for(int i = 0; i < p->length; i++)
	{
		printf("%d ", p->list[i]);
	}
	printf("\n");
}

//线性表判断是否为空
int isEmpty(list_t* p)
{
	assert(p != NULL);//空指针检查
	if(p->length == 0)
		return true;
	else
		return false;
}

//返回顺序表大小
int sizeList(list_t* p)
{
	assert(p != NULL);//空指针检查
	return p->length;
}

//按指定的元素查找
void findByData(list_t* p, DataType data)
{
	assert(p != NULL);//空指针检查
	if(p->length == 0)
	{
		printf("There is nothing to find because list is null!\n");
		return;
	}
	for(int i=0; i < p->length; i ++)
	{
		if (data == p->list[i])
		{
			printf("This data is found in arry[%d]\n", i);
		}
	}
}

//按指定的序号查找
void findByNumber(list_t* p, int num)
{
	assert(p != NULL);//空指针检查
	if(num > p->length)
	{
		printf("Find by number failed because exceed size of array!\n");
		return;
	}
	printf("arry[%d] is %d\n", num, p->list[num]);
}

//从头部插入
void insertHead(list_t* p, int data)
{
	assert(p != NULL);//空指针检查
	if(p->length == SIZE)
	{
		printf("Insert data failed because of array is full!\n");
		return;
	}
	for(int i = p->length-1; i >= 0; i --)
	{
		p->list[i+1] = p->list[i];
	}
	p->list[0] = data;
	p->length ++;
}

//从头部删除
void deleteFromHead(list_t* p)
{
	assert(p != NULL);//空指针检查
	if(p->length == 0)
	{
		printf("There is nothing to delete because list is null!\n");
		return;
	}
	for(int i = 0; i < p->length - 1; i ++)
	{
		p->list[i] = p->list[i+1];
	}
	p->length --;
}

//从尾部插入
void insertTail(list_t* p, int data)
{
	assert(p != NULL);//空指针检查
	if(p->length == SIZE)
	{
		printf("Insert data failed because of array is full!\n");
		return;
	}
	p->list[p->length] = data;
	p->length ++;
}

//从尾部删除
void deleteFromTail(list_t* p)
{
	assert(p != NULL);//空指针检查
	if(p->length == 0)
	{
		printf("There is nothing to delete because list is null!\n");
		return;
	}
	p->length --;
}

//从指定位置插入
void insertOrder(list_t* p, int num, DataType data)
{
	assert(p != NULL);//空指针检查
	if(p->length == SIZE)
	{
		printf("Insert data failed because of array is full!\n");
		return;
	}
	for(int i = p->length-1; i >= num; i --)
	{
		p->list[i+1] = p->list[i]; 
	}
	p->list[num] = data;
	p->length ++;
}


//删除指定元素
void deleteOrder(list_t* p, DataType data)
{
	assert(p != NULL);//空指针检查
	if(p->length == 0)
	{
		printf("There is nothing to delete because list is null!\n");
		return;
	}
	int i = 0, flag = 0;
	for(i = 0; i < p->length; i ++)
	{
		if (data == p->list[i])
		{
			flag = 1;
			break;
		}
	}
	for(int j = p->length-1; j > i; j --)
	{
		p->list[j-1] = p->list[j]; 
	}
	if(flag)
	{
		p->length --;
		flag = 0;
	}
}

//删除所有指定元素
void deleteAllOrder(list_t* p, DataType data)
{
	assert(p != NULL);//空指针检查
	if(p->length == 0)
	{
		printf("There is nothing to delete because list is null!\n");
		return;
	}
	int i, j = 0, flag = 0;
	for(i = 0; i < p->length; i ++)
	{
		if (data != p->list[i])
		{
			p->list[j] = p->list[i]; 
			j++;
		}
	}
	p->length = j;
}

void testInsertAndDelete()
{
	list_t t;
	initList(&t);
	insertTail(&t, 10);
	insertTail(&t, 10);
	insertTail(&t, 12);
	insertHead(&t, 1);
	insertHead(&t, 2);
	insertHead(&t, 3);
	printList(&t);
	findByNumber(&t, 3);
	findByData(&t, 10);
	deleteFromHead(&t);
	printList(&t);
	deleteFromTail(&t);
	printList(&t);
	insertOrder(&t, 1, 3);
	insertOrder(&t, 2, 2);
	printList(&t);
	deleteOrder(&t, 1);
	printList(&t);
	deleteOrder(&t, 10);
	printList(&t);
	deleteAllOrder(&t, 2);
	printList(&t);
}

int main()
{
	testInsertAndDelete();

	return 0;
}

