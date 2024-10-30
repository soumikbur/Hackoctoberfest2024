#include<stdio.h>

//prototype
void magic(int);

void main()
{
    int n;
    printf("Enter odd order of matrix : ");
    scanf("%d",&n);
    magic(n);
}

void magic(int n)
{
    int mat[100][100];
    int k,i=n/2,j=n-1;
    if(n%2!=0)
    {
        for(k=1;k<=n*n;k++)
        {
            if((i==-1)&&(j==n))
            {
                i=0;
                j=n-2;
                mat[i][j]=k;
            }
            else if(i==-1)
            {
                i=n-1;
                mat[i][j]=k;
            }
            else if(j==n)
            {
                j=0;
                mat[i][j]=k;
            }
            else if((mat[i][j]>=1)&&(mat[i][j]<=n*n))
            {
                i++;
                j-=2;
                mat[i][j]=k;
            }
            else
                mat[i][j]=k;
            i--;
            j++;
        }
        printf("Magic square of order %d :\n",n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d ",mat[i][j]);
            printf("\n");
        }
    }
    else
        printf("Magic square is not possible for even order of a matrix");
}
