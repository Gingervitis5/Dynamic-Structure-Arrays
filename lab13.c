#include "lab13.h"
#include "utils/utils.h"
#include <stdlib.h>
#include <stdio.h>

int menu(){
   int choice = 0;
   do {
       printf("Choose from the following:\n"
              "1) Print the array sorted by street\n"
              "2) Print the array sorted by city\n"
              "3) Print the array sorted by state then city then by zip\n"
              "4) Print the array sorted by zip\n"
              "5) Quit\n"
              "Enter you choice-> ");
       scanf("%d", &choice);
   } while (choice < 1 || choice > 5);

   return choice;
}

Address * fillArray(int * total, FILE * fin){
    int count = 0; char line[100];
    fgets(line, 100, fin);
    while (!feof(fin)){
        count++;
        fgets(line, 100, fin);
    }

    if (count == 0 || count % 4 != 0){
        printf("Error in file");
        return NULL;
    }

    *total = count/4;
    rewind(fin);

    Address *array;
    array = (Address*)calloc(*total, sizeof(Address));
    int x = 0;
    for (x; x <*total && !feof(fin); x++){
        fgets(line, 100, fin);
        strip(line);
        array[x].street = (char *)calloc(strlen(line)+1, sizeof(char));
        strcpy(array[x].street, line);

        fgets(line, 100, fin);
        strip(line);
        array[x].city = (char *)calloc(strlen(line)+1, sizeof(char));
        strcpy(array[x].city, line);

        fgets(line, 100, fin);
        strip(line);
        array[x].state = (char *)calloc(strlen(line)+1, sizeof(char));
        strcpy(array[x].state, line);

        fscanf(fin, "%d", &array[x].zip);
        fgets(line, 100, fin);
    }

    return array;
}

void printArray(Address * array, int total){
    int x = 0;
    for(x; x < total; x++){
    printf("%s \n%s  %s  %d\n", array[x].street, array[x].city, array[x].state, array[x].zip);
    printf("\n");
    }
    printf("\n");
}

void cleanUp(Address * array, int total){
    int x = 0;
    for (x; x < total; x++){
        free(array[x].street);
        free(array[x].state);
        free(array[x].city);
    }
    free(array);
}

int compareStreet(const void * one, const void * two){
    Address *a1 = (Address *)one;
    Address *a2 = (Address *)two;
    return (strcmp(a1->street, a2->street));
}

int compareCity(const void * one, const void * two){
    Address *a1 = (Address *)one;
    Address *a2 = (Address *)two;
    return (strcmp(a1->city, a2->city));
}

int compareStateCityZip(const void * one, const void * two){
    Address *a1 = (Address *)one;
    Address *a2 = (Address *)two;
    if (strcmp(a1->state, a2->state) == 0){

        if (strcmp(a1->city, a2->city) == 0){

            return ((a1->zip) - (a2->zip));
        }
        return strcmp(a1->city, a2->city);
    }
    return strcmp(a1->state, a2->state);
}

int compareZip(const void * one, const void * two){
    Address *a1 = (Address *)one;
    Address *a2 = (Address *)two;
    return (a1->zip - a2->zip);
}

