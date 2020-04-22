#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <time.h>


void Random(int *array, long size);
void swap(int *tmp1, int *tmp2);
void quickSort(int arr[], int left, int right);
void printArrToFile(int array[], long size, char* name);
void LinearSearch(int array[], int aKey, long SIZE);
#endif
