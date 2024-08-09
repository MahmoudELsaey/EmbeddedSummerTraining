#include <stdio.h>
#include <stdlib.h>

int main()
{
     int result;

     do
     {
     printf("Enter the result of 3*4\n");
     scanf ("%d", &result);
     }
     while (result != 12);

     printf("Thanks");

     return 0;
}
