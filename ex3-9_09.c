#include <stdio.h>

void main()
{
	int i;
	char string1[20]="Dreams come true!",string2[20],*ptr1, *ptr2,*ptr3;

	ptr1 = string1;
	printf("\n string1ÀÇ ÁÖ¼Ò = %u \t ptr1 = %u", string1, ptr1);
	printf("\n string1 = %s \n ptr1 = %s", string1, ptr1);
	printf("\n\n %s",ptr1+7);
	ptr2 = &string1[7];
	printf("\n %s \n\n ",ptr2);

	for(i=16;i>=0;i--)
	{
		putchar(*(ptr1+i));
	}
	for(i=0;i<20;i++){
		string2[i] = *(ptr1+i);
	}
	printf("\n\n string1 = %s",string1);
	printf("\n string2 = %s", string2);

	ptr3=string1;

	*ptr3++ = 'P';
	*ptr3++ = 'e';
	*ptr3++ = 'a';
	*ptr3++ = 'c';
	*ptr3++ = 'e';
	printf("\n\n string1 = %s\n",string1);

	getchar();
}