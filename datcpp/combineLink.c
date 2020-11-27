#include <stdio.h>
#include <stdlib.h>

// 定义结点类型
typedef struct Node 
{
	int data;
	struct Node* next;
} node_t;


node_t* combine(node_t* head1, node_t* head2)
{
	node_t* head = NULL;

	return head;
}

void printLink(node_t* head)
{
	node_t* tmp = head->next;
	while(tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

node_t* createLink()
{
	// 创建头部结点
	node_t* head = (node_t*)malloc(sizeof(node_t));
	head->next = NULL;

	node_t* tmp = head;
	for(int i = 0; i < 5; i ++) {
		node_t* newNode = (node_t*)malloc(sizeof(node_t));
		newNode->data = i * 2 + 1;
		newNode->next = NULL;
		tmp->next = newNode;
		tmp = tmp->next;
	}

	return head;
}

int main()
{
	// 创建链表1
	node_t* link1 = createLink();
	printLink(link1);

	return 0;
}

