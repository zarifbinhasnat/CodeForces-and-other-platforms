#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int rows,cols;
    printf("Enter the number of rows and columns\n")
    scanf("%d %d",&rows,&cols);
    int **arr = (int **)malloc(rows * sizeof(int *));
    for(int i=0;i<rows;i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    

}