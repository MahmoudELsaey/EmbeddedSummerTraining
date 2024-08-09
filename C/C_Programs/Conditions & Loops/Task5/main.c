#include <stdio.h>
#include <stdlib.h>

int main()
{
   float x,y,z;
   printf("Enter the 3 Numbers\n");
   scanf("%f", &x);
   scanf("%f", &y);
   scanf("%f", &z);

   if (x>y)
   {
       if (x>z)
        printf("%.2f is the Maximum", x);
       else
        printf("%.2f is the Maximum", z);
   }
   else
   {
       if (y>z)
        printf("%.2f is the Maximum", y);
       else
        printf("%.2f is the Maximum", z);
   }
}
