#include <stdio.h>
#include <stdlib.h>

// 定义结点类型
typedef struct Node 
{
	int data;
	struct Node* next;
} node_t;

node_t* reverseLink(node_t* head) 
{
	node_t* tmp = head->next;
	head->next = NULL;
#if 0
	while(tmp != NULL) {
		tmp->next = head;
		head = tmp;
		
		tmp = tmp->next;
	}
#else
	node_t* q;
	while(tmp != NULL) {
		q = tmp->next;
		tmp->next = head;
		head = tmp;
		tmp = q;
	}
#endif
	return head;
}

node_t* combine(node_t* head1, node_t* head2)
{
	node_t* head = (node_t*)malloc(sizeof(node_t));//合并头结点
	node_t* tmp1 = head1->next;// 指向链表1第一个元素
	node_t* tmp2 = head2->next;// 指向链表2第一个元素
	node_t* tmp = head;
	while(tmp1 != NULL && tmp2 != NULL) {
	
		if(tmp1->data <= tmp2->data) {
			tmp->next = tmp1;
			tmp = tmp1;
			tmp1 = tmp1->next;
		}
		else
		{
			tmp->next = tmp2;
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
	}
	
	if(tmp1 != NULL) tmp->next = tmp1;

	if(tmp2 != NULL) tmp->next = tmp2;
	
	head1->next = NULL;
	head2->next = NULL;

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
		newNode->data = i*2 + 1;
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
	
	// 创建链表2
	node_t* link2 = createLink();
	printLink(link2);
	
	node_t* link3 = reverseLink(link1); 
	printLink(link3);

	//node_t* link4 = combine(link1, link2);
	//printLink(link4);

	return 0;
}

