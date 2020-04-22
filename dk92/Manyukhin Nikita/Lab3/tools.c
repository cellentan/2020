#include "tools.h"
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void Random(int *array, long size) {
	setlocale(LC_ALL, "RUS");
    register int i;
    for(i = 0; i < size; i++)
    {
        array[i] = rand() % 10000;
    }

}

void swap(int *tmp1, int *tmp2)
{
    int tmp = *tmp1;
    *tmp1 = *tmp2;
    *tmp2 = tmp;
}

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int center = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < center)
            i++;
        while (arr[j] > center)
            j--;
        if (i <= j) {
                swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    };
    if (left < j)
    {
        quickSort(arr, left, j);
    }
    if (i < right)
    {
        quickSort(arr, i, right);
    }
}

void printArrToFile(int array[], long size, char* name) {
    FILE *file = fopen(name, "w");
    if(file == 0)
	{
		printf("File not created!\n");
		free(array);
		return 2;
	}
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", array[i]);
        if (i % 50 == 0 && i != 0) {
            fprintf(file, "\n");
        }
    }
}

void LinearSearch(int array[], int aKey, long SIZE)
{
    unsigned int start = clock();
    FILE *file = fopen("Finded.txt", "a+");
    fprintf(file, "You were looking for a number %d, adress of this number: \n", aKey);
    for(int i = 0; i < SIZE; i++)
    {
        if(array[i] == aKey)
        {
            fprintf(file, "Array[%d]\n",i);
        }

    }

    unsigned int end = clock();
    unsigned int time = end - start;
    printf("LinearSearch Func Time: %dms\n", time);
    fclose(file);
}
