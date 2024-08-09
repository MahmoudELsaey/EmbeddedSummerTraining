#include <stdio.h>
#include <stdlib.h>

int main()
{
   int number;
   printf("Enter the number\n");
   scanf("%d",&number);

   int i = number;
   int factorial=1;
   while (i>0)
   {
       factorial *= i;
       i--;
   }
   printf("%d", factorial);

    return 0;
}
