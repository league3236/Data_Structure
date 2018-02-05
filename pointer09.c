//{40,20,50,30,10} 다섯 개의 정수들을 주어진 순서대로 original[]에 저장한다.
//original[]을 수정하지 않고, 포인터 배열 sort[]를 이용하여 오름차 순으로 출력하게 한다.

#include <stdio.h>

void main()
{
	int original[5] = {40,20,50,30,10};
	int *sort[5];
	int i,j,min;
	*sort=original;
	printf("저장된 정수순서: ");
	
	for(i=0;i<5;i++)
		printf("%d ",*(sort[0]+i));
	
	printf("\n");
	
	for(j=0;j<5;j++)
	{
		for(i=0;i<4;i++)
		{
			if(*(sort[0]+i)>*(sort[0]+i+1))
			{
				min=*(sort[0]+i+1);
				*(sort[0]+i+1)=*(sort[0]+i);
				*(sort[0]+i)=min;
			}
		}
	}
	printf("출력된 정수순서: ");
	for(i=0;i<5;i++)
		printf("%d ",original[i]);
	
	printf("\n");
	
	getchar();
}