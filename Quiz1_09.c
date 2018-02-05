#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode{			//���׽� ����Ʈ�� ��� ���� ����
	float coef;
	int expo;
	struct ListNode *link;
}ListNode;

typedef struct ListHead{			//���׽� ����Ʈ�� ��� ��� ���� ����
	ListNode *head;
}ListHead;

ListHead *createLinkedList(void)	//���� ���׽� ����Ʈ ���� ����
{
	ListHead *L;
	L=(ListHead *)malloc(sizeof(ListHead));
	L->head=NULL;
	return L;
}

void addLastNode(ListHead *L,float coef, int expo)//���׽� ����Ʈ�� ������ ��� ���� ����
{
	ListNode *newNode;
	ListNode *p;
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->coef=coef;
	newNode->expo=expo;
	newNode->link=NULL;
	if(L->head==NULL){		//���� ���׽� ����Ʈ�� ������ ���,
		L->head=newNode;
		return;
	}
	else					//���� ���׽� ����Ʈ�� ������ �ƴѰ��,
	{
		p=L->head;
		while(p->link!=NULL){	//��Ʈ�� ������ ��带 ã�Ƽ�
			p=p->link;
		}
		p->link=newNode;			//������ ������ ��� �ڿ� �� ��带 �����Ѵ�.
	}
}

void addPoly(ListHead *A, ListHead *B, ListHead *C)			//�� ���׽��� ���� ���ϴ� ����
{
	ListNode *pA=A->head;
	ListNode *pB=B->head;
	float sum;

	while(pA&&pB){			//�δ��׽Ŀ� ��尡 �ִ� ���� �ݺ� ����
		if(pA->expo==pB->expo){		//���׽� A�� ������ ���׽� B�� ������ ���� ���
			sum=pA->coef+pB->coef;
			addLastNode(C,sum,pA->expo);
			pA=pA->link,pB=pB->link;
		}
		else if(pA->expo>pB->expo){	//���׽� A�� ������ ���׽� B�� �������� ū ���
			addLastNode(C,pA->coef,pA->expo);
			pA=pA->link;
		}
		else if(pA->expo<pB->expo){	//���׽� B�� ������ ���׽� A�� �������� ū ���
			addLastNode(C,pB->coef,pB->expo);
			pB=pB->link;
		}
	}
	for(;pA!=NULL;pA=pA->link)
		addLastNode(C,pA->coef,pA->expo);
	for(;pB!=NULL;pB=pB->link)
		addLastNode(C,pB->coef,pB->expo);
}

void minusPoly(ListHead *A, ListHead *B, ListHead *C)			//�� ���׽��� ���� ���ϴ� ����
{
	ListNode *pA=A->head;
	ListNode *pB=B->head;
	float minus1,minus2;

	while(pA&&pB){			//�δ��׽Ŀ� ��尡 �ִ� ���� �ݺ� ����
		if(pA->expo==pB->expo){		//���׽� A�� ������ ���׽� B�� ������ ���� ���
			if((pA->coef)>(pB->coef))
			{
				minus1=(pA->coef)-(pB->coef);
				addLastNode(C,minus1,pA->expo);
				pA=pA->link,pB=pB->link;
			}
			else if((pA->coef)<(pB->coef))
			{
				minus2=(pB->coef)-(pA->coef);
				addLastNode(C,minus2,pB->expo);
				pA=pA->link,pB=pB->link;
			}
			else{
				pA=pA->link,pB=pB->link;
			}
		}
		else if(pA->expo>pB->expo){	//���׽� A�� ������ ���׽� B�� �������� ū ���
			addLastNode(C,pA->coef,pA->expo);
			pA=pA->link;
		}
		else if(pA->expo<pB->expo){	//���׽� B�� ������ ���׽� A�� �������� ū ���
			addLastNode(C,-(pB->coef),pB->expo);
			pB=pB->link;
		}
	}
	for(;pA!=NULL;pA=pA->link)
		addLastNode(C,pA->coef,pA->expo);
	for(;pB!=NULL;pB=pB->link)
		addLastNode(C,-(pB->coef),pB->expo);
}

void printPoly(ListHead *L)		//���׽� ����Ʈ�� ����ϴ� ����
{
	ListNode *p=L->head;
	for(;p;p=p->link){
		printf("%3.0fx^%d",p->coef,p->expo);
	}
}


void main(void){
	ListHead *A,*B,*C,*D;

	A=createLinkedList();			//���� ���׽� ����Ʈ A,B,C �����ϱ�
	B=createLinkedList();
	C=createLinkedList();
	D=createLinkedList();

	addLastNode(A,4,3);				//���׽� ����Ʈ A�� 4x^3 ��� �߰�
	addLastNode(A,3,2);				//���׽� ����Ʈ A�� 3x^2 ��� �߰�
	addLastNode(A,5,1);				//���׽� ����Ʈ A�� 5x^1 ��� �߰�
	printf("\n A(x)=");
	printPoly(A);					//���׽� ����Ʈ A ����ϱ�

	addLastNode(B,3,4);				//���׽� ����Ʈ B�� 3x^4 ��� �߰�
	addLastNode(B,1,3);				//���׽� ����Ʈ B�� 1x^3 ��� �߰�
	addLastNode(B,2,1);				//���׽� ����Ʈ B�� 2x^1 ��� �߰�
	addLastNode(B,1,0);				//���׽� ����Ʈ B�� 1x^0 ��� �߰�
	printf("\n B(x)=");
	printPoly(B);					//���׽� ����Ʈ B ����ϱ�

	addPoly(A,B,C);					//���׽��� ���� ���� ����
	printf("\n C(x)=");
	printPoly(C);					//���׽� ����Ʈ C����ϱ�

	minusPoly(C,A,D);
	printf("\n D(x)=");
	printPoly(D);
	getchar();
}
