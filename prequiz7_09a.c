#include <stdio.h>
#define size 5

typedef struct{
	long number;
	char name[10];
	int birth;
}student;

int main(void)
{
	int i=0;
	student f[size];
	char answer;
	do{
		printf("enter a student number? ");
		scanf("%d",&f[i].number);
		printf("enter a name? ");
		scanf("%s",&f[i].name);
		printf("enter a birthday?(yymmdd) ");
		scanf("%d",&f[i].birth);
		answer=getchar();
		printf("enter another(y/n)?");
		scanf("%c",&answer);
		i++;
	}while((answer!='n')&&(i<size));
	printf("    학번           이름         생년월일  ");
	printf("-----------     ---------    -------------  ");
	for(i=0;i<size;i++)
		printf("%d    %s      %d\n",f[i].number,f[i].name,f[i].birth);

	return 0;
}

	