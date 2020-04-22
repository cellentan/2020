#include <stdio.h>
#include <locale.h>
#include "tools.h"
int main() {
    remove("Finded.txt");

    long SIZE;
    int aKey;
    printf("Enter size of Massive(0-10000): \n");
    do
    {
        scanf("%d", &SIZE);
        if (SIZE < 0 || SIZE > 10000) printf ("#####ERROR#####\nEnter another(0-10000): \n");
    }while (SIZE < 0 || SIZE > 10000);

    int i, a[SIZE];

    int *array = (int *) malloc(sizeof(int) * SIZE);

    Random(a, SIZE);
    printArrToFile(a, SIZE, "unsortedArray.txt");

    unsigned int start = clock();
    quickSort(a, 0, SIZE - 1);
    unsigned int end = clock();
    unsigned int time = end - start;
    printf("QuickSort Func Time: %dms\n", time);
    printArrToFile(a, SIZE, "sortedArray.txt");

    printf("Please enter the Key: \n");
    scanf("%d", &aKey);
    LinearSearch(a, aKey, SIZE);
}
