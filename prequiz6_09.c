/*2013301004 ������
������ �迭�� �̿��Ͽ�
5���� �����Ը� �Է¹޾� ������
���� ����ϴ� ���α׷��� ����ÿ�*/

#include <stdio.h>

int max(int a[]);
int min(int a[]);
double aver(int a[]);


int main(void)
{
	int weight[5];
	int i;

	printf("enter 5 weights? ");
	for(i=0;i<5;i++)
		scanf("%d",&weight[i]);
	printf("maximum: %d  minimum: %d  average: %0.1lf\n",max(weight),min(weight),aver(weight));

	return 0;
}

int max(int a[])
{
	int i;
	int max=0;

	for(i=0;i<5;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
int min(int a[])
{
	int i;
	int min=a[0];
	for(i=0;i<5;i++)
	{
		if(a[i]<min)
			min=a[i];
	}
	return min;
}
double aver(int a[])
{
	int i;
	double sum=0;
	for(i=0;i<5;i++)
		sum+=a[i];
	return sum/5;
}