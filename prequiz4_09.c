/*2013301004 ������
���ĺ� �ѹ��ڸ� �Է¹޾� �ҹ��ڴ� �빮�ڷ�
�빮�ڴ� �ҹ��ڷ� ����ϴ� ���α׷��� ����ÿ�.
���� �Լ��� �����Ͽ� �ۼ��Ͻÿ�.

#include <stdio.h>

int validinput(char c); //if(a..z||A..Z) return 1 else -1
char change(char c);//�ҹ��ڴ� �빮�ڷ� �빮�ڴ� �ҹ��ڷ� ��ȯ

int main(void)
{
	char x,y,answer;
	int vali;
	do{
		do{
			printf("enter an alphabet?");
			scanf("%c",&x);
			vali=validinput(x);
			if(vali!=1)
			{
				printf("invalid input\n");
				x=getchar();
			}
		}while(vali!=1);
		y=change(x);
		printf("%c\n",y);
		getchar();
		printf("continue(y/n)?");
		scanf("%c",&answer);
		x=getchar();
	}while(answer!='n');
	printf("program end\n");
	return 0;
}
int validinput(char c)
{
	if((c>='a')&&(c<='z')||(c>='A')&&(c<='Z'))
		return 1;
	else
		return -1;
}
char change(char c)
{
	if((c>='a')&&(c<='z'))
		return c-32;
	else
		return c+32;
}*/