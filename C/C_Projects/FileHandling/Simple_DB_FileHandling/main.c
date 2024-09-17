#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_STUDENTS 2
#define MAX_SIZE_OF_WRITTEN_LINE 87

FILE *myFile = NULL;

typedef struct
{
    char Name[50];
    short int id;
    float degree;
}student_info; //56 Byte
int main (void)
{
    //Writing Data
    myFile = fopen("text.txt", "w");
    if (NULL != myFile)
        printf("File opened Successfully \n");
    else
        printf("Error");

    student_info student;
    for(int counter =0; counter <NUMBER_OF_STUDENTS; counter++)
    {
        printf("Enter your name\n");
        gets (student.Name);
        printf("Enter your Id\n");
        scanf("%hd", &student.id);
        printf("Enter your Degree\n");
        scanf("%f", &student.degree);
        fflush(stdin);
        fprintf(myFile, "Name: [%s] - ID: [%hd] - Degree: [%.2f]\n", student.Name, student.id, student.degree);
    }

    fclose(myFile);
    if (NULL != myFile)
        printf("File closed succesfully \n");
    else
        printf("Error");


    //Reading from the File
    myFile = fopen("text.txt", "r");
    char CopyOfData[MAX_SIZE_OF_WRITTEN_LINE];
    if (NULL != myFile)
        printf("File opened Successfully \n");
    else
        printf("Error");

    printf("==============================\n");
    for(int counter =0; counter <NUMBER_OF_STUDENTS; counter++)
    {
        fgets(CopyOfData, MAX_SIZE_OF_WRITTEN_LINE, myFile);
        printf("The Data: %s", CopyOfData);
    }
    printf("==============================\n");

    fclose(myFile);
    if (NULL != myFile)
        printf("File closed succesfully \n");
    else
        printf("Error");
}
