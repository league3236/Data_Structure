//{40,20,50,30,10} �ټ� ���� �������� �־��� ������� original[]�� �����Ѵ�.
//original[]�� �������� �ʰ�, ������ �迭 sort[]�� �̿��Ͽ� ������ ������ ����ϰ� �Ѵ�.

#include <stdio.h>

void main()
{
	int original[5] = {40,20,50,30,10};
	int *sort[5];
	int i,j,min;
	*sort=original;
	printf("����� ��������: ");
	
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
	printf("��µ� ��������: ");
	for(i=0;i<5;i++)
		printf("%d ",original[i]);
	
	printf("\n");
	
	getchar();
}