#include <stdio.h>

/*입력한 숫자의 구구단 출력하기*/
void main()
{
	int i=0, n;
	int multiply[9];
	char answer; 

	do{
		do{
		printf("\n1~9의 정수를 입력하세요! : ");
		scanf("%d", &n);
		fflush(stdin);
		}while(n<1||n>9);
		printf("출력하시겠습니까?(y/n)");
		scanf("%c",&answer);
	}while(answer!='y');
	printf("\n");
	for(i=0;i<9;i++)
	{
		multiply[i]=n+(i+1);
		printf(" %d * %d = %d\n",n,(i+1),multiply[i]);
	}
}