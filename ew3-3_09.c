#include <stdio.h>

/*�Է��� ������ ������ ����ϱ�*/
void main()
{
	int i=0, n;
	int multiply[9];
	char answer; 

	do{
		do{
		printf("\n1~9�� ������ �Է��ϼ���! : ");
		scanf("%d", &n);
		fflush(stdin);
		}while(n<1||n>9);
		printf("����Ͻðڽ��ϱ�?(y/n)");
		scanf("%c",&answer);
	}while(answer!='y');
	printf("\n");
	for(i=0;i<9;i++)
	{
		multiply[i]=n+(i+1);
		printf(" %d * %d = %d\n",n,(i+1),multiply[i]);
	}
}