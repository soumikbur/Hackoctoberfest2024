#include<stdio.h>
//prototype
void multiply(int ,int ,int,int mat1[30][30],int mat2[30][30]);
void main()
{
    int mat1[30][30],mat2[30][30];
    int m,n,p,i,j,k;
    printf("Enter the number of rows and columns for 1st matrix: ");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of the 1st matrix\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&mat1[i][j]);
    //no of col of 1st matrix = no of rows of 2nd matrix
    printf("Enter the number of columns for 2nd matrix: "); 
    scanf("%d",&p);
    printf("Enter the elements of the 2nd matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<p;j++)
            scanf("%d",&mat2[i][j]);
    printf("The 1st matrix\n"); //The resultant 1st matrix
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",mat1[i][j]);
        printf("\n");
    }
    printf("The 2nd matrix\n"); //The resultant 2nd matrix
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
            printf("%d ",mat2[i][j]);
        printf("\n");
    }
    multiply(m,n,p,mat1,mat2);
}

void multiply(int m,int n,int p,int mat1[30][30],int mat2[30][30])
{
    int mul[30][30],i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
        {
            mul[i][j]=0;
            for(k=0;k<n;k++)
                mul[i][j]=mul[i][j]+mat1[i][k]*mat2[k][j];
        }
    }
    printf("The resultant matrix after multiplying the two matrices\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
            printf("%d ",mul[i][j]);
        printf("\n");
    }
}

