#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, summation=0;

    for(int i =1; i<=10; i++)
    {
        printf("Enter number %d \n", i);
        scanf("%d", &n);
        summation+=n;
    }
    printf("Summation = %d\n", summation);

    float average = (summation/10);
    printf("Average = %.2f\n", average);

    return 0;
}
