#include <stdio.h>
#include <stdlib.h>

int main()
{
    float grade;

    printf("Enter your grade\n");
    scanf ("%f", &grade);

    if (grade >= 85)
        printf("Excellent");
    else if (grade >= 75)
        printf("Very Good");
    else if (grade >= 65)
        printf("Good");
    else if (grade >= 50)
        printf("Succeded");
    else
       printf("Failed");


    return 0;

}
