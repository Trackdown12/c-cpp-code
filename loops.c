#include <stdio.h>
int main()
{
    int num1 , num2=0;
    printf("enter you numbers" , num1);
    scanf("%d" , &num1);
for ( int i  = 0; i <=num1 ; i++)
{
    num2=num2+i;
}
printf("%d",num2);
return 0;
}