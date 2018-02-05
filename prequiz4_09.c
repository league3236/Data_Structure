/*2013301004 곽승혁
알파벳 한문자를 입력받아 소문자는 대문자로
대문자는 소문자로 출력하는 프로그램을 만드시오.
다음 함수를 포함하여 작성하시오.

#include <stdio.h>

int validinput(char c); //if(a..z||A..Z) return 1 else -1
char change(char c);//소문자는 대문자로 대문자는 소문자로 변환

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