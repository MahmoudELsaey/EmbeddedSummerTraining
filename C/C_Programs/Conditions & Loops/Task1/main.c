#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Salary;
    float HoursNumber;

    printf("enter how many hours do you work \n");
    scanf("%f", &HoursNumber);

    if (HoursNumber < 40)
    {
        Salary = (HoursNumber * 50) - (0.1*(HoursNumber * 50));
    }
    else
    {
        Salary = HoursNumber * 50;
    }
    printf("%.2f", Salary);


    return 0;
}
