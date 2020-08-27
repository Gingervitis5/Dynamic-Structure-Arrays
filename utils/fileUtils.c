#include "fileUtils.h"

FILE * openInputFile()
{
    char temp[MAX];
    FILE * inf = NULL;
    do
    {
        printf("Please enter the name of the input file ");
        scanf("%s", temp);
        inf = fopen(temp, "r");
    }while(inf == NULL);
    return inf;
}

FILE * openOutputFile()
{
    char temp[MAX];
    FILE * onf =NULL;
    while(fgetc(stdin) != '\n');
    printf("Please enter the name of the output file ");
    scanf("%s", temp);
    onf = fopen(temp, "w");
    if(onf == NULL)
        exit(-1);

    return onf;
}

