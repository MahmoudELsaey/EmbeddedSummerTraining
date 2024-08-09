#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("Enter the number\n");
    scanf("%d",&i);

    for(int j=0;j<=12;j++)
    {
        printf("%d * %d = %d\n",i,j,i*j);
    }
    return 0;
}
