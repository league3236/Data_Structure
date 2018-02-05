#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct stackNode{
 element data;
 struct stackNode *link;
} stackNode;

stackNode* top;

void push(element item)
{
 stackNode* temp=(stackNode *)malloc(sizeof(stackNode));
 temp->data=item;
 temp->link=top;
 top=temp;
}

element pop()
{
 element item;
 stackNode* temp=top;

 if(top=NULL){
  printf("\n\n Stack is empty !\n");
  return 0;
 }
 else{
  item=temp->data;
  top=temp->link;
  free(temp);
  return item;
 }
}

element peek()
{
 element item;
 if(top==NULL){
  printf("\n\n Stack is empty ! \n");
  return 0;
 }
 else{
  item=top->data;
  return item;
 }
}

void del()
{
 stackNode* temp;
 if(top==NULL){
  printf("\n\n Stack is empty !\n");
 }
 else{
  temp=top;
  top=top->link;
  free(temp);
 }
}

void printStack()
{
 stackNode* p=top;
 printf("\n STACK [");
  while(p){
   printf(" %c ",p->data);
   p=p->link;
  }
  printf(" ]");
}

void main(void)
{
 char a[]="abcdef";
 element i=0;
 top=NULL;

 printf("문자열:%s\n",a);

 while(a[i]!=NULL)
 {
	push(a[i]);
	i++;
 }
 printf("역순:");
 while(top!=NULL)
 {
		printf("%c",pop());
 }
 getchar();
}

 
