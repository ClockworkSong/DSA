#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	int data;
	struct Stack* next;
}stack_t;

//stack为当前的链栈，elem为入栈元素
stack_t* push(stack_t* p, int elem)
{
	stack_t* tmp = p;
	stack_t* q = (stack_t*)malloc(sizeof(struct Stack));
	if(q == NULL) exit(-1);
	q->data = elem;
	q->next = tmp->next;
	tmp->next = q;
	printf("入栈元素:%d\n", tmp->next->data);
	return p;
}

stack_t* pop(stack_t* p)
{
	stack_t* tmp = p;
	if(tmp->next == NULL)
	{
		printf("空栈\n");
		return tmp;
	}
	printf("出栈元素:%d\n", tmp->next->data);
	tmp->next = tmp->next->next;
	p = tmp;
	//free(tmp->next);
	return p;
}

int main()
{
	stack_t* t = (stack_t*)malloc(sizeof(struct Stack));
	if(t == NULL) exit(-1);
	t = push(t, 10);
	t = push(t, 20);
	t = push(t, 30);
	t = pop(t);
	t = pop(t);
	t = pop(t);
	t = pop(t);

	return 0;
}


