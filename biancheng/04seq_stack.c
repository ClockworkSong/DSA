#include <stdio.h>
#include <stdlib.h>

//元素elem进栈,a为数组,top值为当前栈的栈顶位置
int push(int* a, int top, int elem)
{
	a[++top] = elem;
	return top;
}

//元素出栈
int pop(int* a, int top)
{
	if(top == -1) 
	{
		printf("空栈\n");
		return -1;
	}
	printf("弹出元素:%d\n", a[top]);
	top --;
	return top;
}

int main()
{
	int arr[10];
	int top = -1;
	
	top = push(arr, top, 10);
	top = push(arr, top, 20);
	top = pop(arr, top);
	top = pop(arr, top);
	top = pop(arr, top);

	return 0;
}

