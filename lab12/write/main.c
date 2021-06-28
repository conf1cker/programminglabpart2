#include "lib.h"

#define size1 5
#define size2 3

int main()
{
    int size3;
    size3 = size1 + size2;
    int* mas1 = (int*)malloc(size1 * sizeof(int));
    int* mas2 = (int*)malloc(size2 * sizeof(int));
    int* mas3 = (int*)malloc((size1+ size2) * sizeof(int));
    fill_mas1(size1,mas1);

    fill_mas2(size2,mas2);

    fill_mas3(size3, size1, size2, mas1, mas2, mas3);


    sort_mas3(size3, mas3);

    print_mas3(mas3, size3);
    free(mas1);
    free(mas2);
    free(mas3);
    return 0;
}