#ifndef LAB13_H
#define LAB13_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct address
{
    char * street;
    char * city;
    char * state;
    int zip;
};

typedef struct address Address;

int menu();

Address * fillArray(int * total, FILE * fin);
void printArray(Address * array, int total);
void cleanUp(Address * array, int total);

int compareStreet(const void * one, const void * two);
int compareCity(const void * one, const void * two);
int compareStateCityZip(const void * one, const void * two);
int compareZip(const void * one, const void * two);

#endif
