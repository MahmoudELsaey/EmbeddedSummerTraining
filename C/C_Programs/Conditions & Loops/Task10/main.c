#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaring the variables
    int id;
    int pass;

    //getting the ID
    printf("Enter the ID");
    scanf("%d", &id);
    if (id>0)
    {
        //getting the pass
        printf("Enter your password");
        scanf("%d", &pass);

        for(int i =0; i<2; i++)
        {
            if (pass>0)
            {
                printf("You are welcomed\n");
                break;
            }

            else
            {
                printf("Enter your password again");
                scanf("%d", &pass);
            }
        }
        //After entering the pass wrong 3 times
        printf("your password is incorrect");
    }

    else
    {
        printf("Your ID is incorrect");
    }


    return 0;
}
