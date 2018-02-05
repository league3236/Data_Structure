#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{			//다항식 리스트의 노드 구조 정의
	float coef;
	int expo;
	struct ListNode *link;
}ListNode;

typedef struct ListHead{			//다항식 리스트의 헤더 노드 구조 정의
	ListNode *head;
}ListHead;

ListHead *createLinkedList(void)	//공백 다항식 리스트 생성 연산
{
	ListHead *L;
	L=(ListHead *)malloc(sizeof(ListHead));
	L->head=NULL;
	return L;
}

void addLastNode(ListHead *L,float coef, int expo)//다항식 리스트에 마지막 노드 삽입 연산
{
	ListNode *newNode;
	ListNode *p;
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->coef=coef;
	newNode->expo=expo;
	newNode->link=NULL;
	if(L->head==NULL){		//현재 다항식 리스트가 공백인 경우,
		L->head=newNode;
		return;
	}
	else					//현재 다항식 리스트가 공백이 아닌경우,
	{
		p=L->head;
		while(p->link!=NULL){	//라스트의 마지막 노드를 찾아서
			p=p->link;
		}
		p->link=newNode;			//현재의 마지막 노드 뒤에 새 노드를 연결한다.
	}
}

void addPoly(ListHead *A, ListHead *B, ListHead *C)			//두 다항식의 합을 구하는 연산
{
	ListNode *pA=A->head;
	ListNode *pB=B->head;
	float sum;

	while(pA&&pB){			//두다항식에 노드가 있는 동안 반복 수행
		if(pA->expo==pB->expo){		//다항식 A의 지수가 다항식 B의 지수와 같은 경우
			sum=pA->coef+pB->coef;
			addLastNode(C,sum,pA->expo);
			pA=pA->link,pB=pB->link;
		}
		else if(pA->expo>pB->expo){	//다항식 A의 지수가 다항식 B의 지수보다 큰 경우
			addLastNode(C,pA->coef,pA->expo);
			pA=pA->link;
		}
		else if(pA->expo<pB->expo){	//다항식 B의 지수가 다항식 A의 지수보다 큰 경우
			addLastNode(C,pB->coef,pB->expo);
			pB=pB->link;
		}
	}
	for(;pA!=NULL;pA=pA->link)
		addLastNode(C,pA->coef,pA->expo);
	for(;pB!=NULL;pB=pB->link)
		addLastNode(C,pB->coef,pB->expo);
}

void printPoly(ListHead *L)		//다항식 리스트를 출력하는 연산
{
	ListNode *p=L->head;
	for(;p;p=p->link){
		printf("%3.0fx^%d",p->coef,p->expo);
	}
}


void main(void){
	ListHead *A,*B,*C;

	A=createLinkedList();			//공백 다항식 리스트 A,B,C 생성하기
	B=createLinkedList();
	C=createLinkedList();

	addLastNode(A,4,3);				//다항식 리스트 A에 4x^3 노드 추가
	addLastNode(A,3,2);				//다항식 리스트 A에 3x^2 노드 추가
	addLastNode(A,5,1);				//다항식 리스트 A에 5x^1 노드 추가
	printf("\n A(x)=");
	printPoly(A);					//다항식 리스트 A 출력하기

	addLastNode(B,3,4);				//다항식 리스트 B에 3x^4 노드 추가
	addLastNode(B,1,3);				//다항식 리스트 B에 1x^3 노드 추가
	addLastNode(B,2,1);				//다항식 리스트 B에 2x^1 노드 추가
	addLastNode(B,1,0);				//다항식 리스트 B에 1x^0 노드 추가
	printf("\n B(x)=");
	printPoly(B);					//다항식 리스트 B 출력하기

	addPoly(A,B,C);					//다항식의 덧셈 연산 수행
	printf("\n C(x)=");
	printPoly(C);					//다항식 리스트 C출력하기

	getchar();
}
