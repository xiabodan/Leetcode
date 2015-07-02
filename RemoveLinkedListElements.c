#include <stdlib.h>
#include <stdio.h>


typedef struct node *list;
typedef struct node *position;
typedef struct node *ListNode;

typedef struct node
{
	int data;
	position next;
}node;

static list init_list(void);
static void delete_list(list L);
static int isempty(list L);
static void insert_node(position L,int data);
static void delete_node(list L,position P);
static position find_last(list L);
static position find_value(list L,int data);
static position find_pre(list L,position P );
static void print(list L);



list init_list(void){
	list L  = (list)malloc(sizeof(node));
	L->next = NULL;
	return L;
}
void delete_list(list L){
	position P ,next;
	P = L;
	do{
		next = P->next;
		free(P);
		P = next;
	}while(next != NULL);
}
int isempty(list L){
	return (L->next == NULL);
}
void insert_node(position P,int data){
	position tem ;
	tem = (position)malloc(sizeof(node));
	tem->data = data;
	tem->next = P->next;
	P->next = tem;
}
void delete_node(list L,position P){
	position pre ;
	pre = find_pre( L, P);
	if(pre != NULL)
	{
		pre->next = P->next;
		free(P);
	}
	else
	{
		printf("delete_node:p is not in the list!\n");
	}
	
}


position find_last(list L){
	position P;
	P=L;
	while(P->next != NULL)
	{
		P = P->next;
	}
	return P;
	
}
position find_value(list L,int data){
	position P ;
	P = L;
	while(P->next != NULL)
	{
		P = P->next;
		if(P->data == data)
			return P;
	}
	return NULL;
}

position find_pre(list L,position P ){
	position tem ;
	tem = L;
	while(tem->next != NULL)
	{
		if(tem->next == P)
			return tem;
		tem = tem->next;
	}
	return NULL;
}
void print(list L){
	position P;
	
	if(isempty( L))
	{
		printf("print: L is a null list!\n");
		return ;
	}
	P = L;
	while(P->next !=NULL)
	{
		P = P->next;
		printf("print:%p : %d \n",P,P->data);
	}
	printf("\n");
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
ListNode removeElements( ListNode head, int val) {
	ListNode P;
	while((P = find_value( head, val)) != NULL)
	{
		delete_node(head,P);
	}
	return head;
}


int main(int argc ,char** argv)
{
	int a[1]= {1};
	int i=0;
	list L;
	L = init_list();

	print(L);
	printf("insert node\n");
	for(i=0;i<1;i++)
	{
		insert_node( L,a[i]);
	}
	print( L);
	L = removeElements(L,1);
	print( L);
}


