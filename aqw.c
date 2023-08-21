/*  4. Enter two array and display them and then find their sums...*/ 

#include<stdio.h>
int main()
{
int array1[10][10],m,n,i,j,array2[10][10],sum[10][10];
printf("enter the size of rows and columns");
scanf("%d%d",&m,&n);
printf("Enter elements of 1st matrix\n");
for (i=0;i<m;++i)
  {
        for (j=0;j<n;++j)
     {
        scanf("%d",&array1[i][j]);
     }
   } 
  printf("Enter elements of 2nd matrix\n");
       for (i=0;i<m;++i)
     {
         for (j=0;j<n;++j)
       {
            scanf("%d",&array2[i][j]);
       }
     } 

    for(i=0;i<m;i++)
  {
     for(j=0;j<n;j++)
      {
        sum[i][j]=array1[i][j]+array2[i][j];
      }
  } 

for(i=0;i<m;++i)
{
  for(j=0;j<n;j++)
{
  printf("%d\t",sum[i][j]);
}
printf("\n");
}

return 0 ;

}
