#include<stdio.h>
void main()
{
	int n,odd[100],even[100],arr[100],i,j=0,k=0;
	printf("Enter the range of array ");
	scanf("%d",&n);
	printf("Enter the elements \n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Array is\n[");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("]\n");
	for(i=0;i<n;i++)
	{
		if(arr[i]%2==0)
		{
			even[j]=arr[i];
			j++;
		}
		else
		{
			odd[k]=arr[i];
			k++;
		}
	}
	printf("\nNumber of even elements: %d\n Even Array: [",j);
	for(i=0;i<j;i++)
		printf("%d ",even[i]);
	printf("]\n");
	printf("\nNumber of odd elements: %d\n Odd Array: [",k);
	for(i=0;i<k;i++)
		printf("%d ",odd[i]);
	printf("]\n");
}		

