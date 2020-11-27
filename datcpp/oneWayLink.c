#include <stdio.h>
#include <stdlib.h>

// 定义结点类型
typedef struct Node 
{
	int data;
	struct Node* next;
} Node, *pNode;


// 初始化
pNode linkInit()
{
	Node* p_node;
	p_node = (Node*)malloc(sizeof(struct Node));
	if(p_node == NULL) {
		perror("malloc");
		exit(0);
	}
	p_node->next = NULL;
	
	return p_node;
}

// 头部插入法创建单链表
pNode linkCreateH()
{
	Node* head;
	head = (Node*)malloc(sizeof(struct Node));
	head->next = NULL;
	
	int x = 0;
	while(scanf("%d", &x) != EOF) {
		Node* newNode;
		newNode = (Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next = head->next;
		head->next = newNode;
	}

	return head;
}

// 尾部插入法创建单链表
pNode linkCreateT()
{
	Node* head;
	head = (Node*)malloc(sizeof(struct Node));
	head->next = NULL;

	Node* tmp = head;
	int x = 0;
	while(scanf("%d", &x) != EOF) {
		Node* newNode;
		newNode = (Node*)malloc(sizeof(struct Node));
		newNode->data = x;
		newNode->next = NULL;
		tmp->next = newNode;
		tmp = tmp->next;	
	}

	return head;
}

// 插入操作,在链表的第i个位置插入x的元素
void linkInsert(pNode head, int i, int x)
{
	pNode tmp = head;
	for(int k = 1; k < i; k ++){
		tmp = tmp->next;
		if(tmp == NULL){
			printf("exceed link node numbers!\n");
			return;
		}
	}
	
	Node* newNode = (Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = tmp->next;
	tmp->next = newNode; 
}

// 删除操作,删除链表中数值为x的元素
void linkDelete(pNode head, int x)
{
	pNode tmp = head->next;
	pNode lastNode = head;
	while(tmp != NULL)
	{
		if(tmp->data == x){
			lastNode->next = tmp->next;
			tmp->next = NULL;
			free(tmp);
			return;
		}
		lastNode = tmp;
		tmp = tmp->next;
	}
}

// 修改操作,修改链表中x的元素为y
void linkReplace(pNode head, int x, int y)
{
	pNode tmp = head->next;
	while(tmp != NULL) {
		if(tmp->data == x) {
			tmp->data = y;
		}
		tmp = tmp->next;
	}
	printf("\n");
}

// 查询操作
void linkPrint(pNode head)
{
	pNode tmp = head->next;
	while(tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

int main()
{
	//pNode node1 = linkCreateH();
	//linkPrint(node1);
	
	pNode node2 = linkCreateT();
	linkPrint(node2);
	linkInsert(node2, 5, 10);
	linkPrint(node2);
	linkDelete(node2, 5);
	linkPrint(node2);
	linkReplace(node2, 1, 99);
	linkPrint(node2);
	

	return 0;
}

