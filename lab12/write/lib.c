#include "lib.h"
void fill_mas1(int size1, int* mas1)
{
    for (int i = 0; i < size1; i++)
    {
        char buf[10] = {0};
        puts("Vvedite %d element  vtorogo masiva ot 1 do 10:\n");
        fread(buf, sizeof(char), 2, stdin);
        *(mas1 + i) = atoi(buf);
    }
}


void fill_mas2(int size2, int* mas2)
{
    for (int i = 0; i < size2; i++)
    {
        printf("Vvedite %d element  vtorogo masiva ot 1 do 10\n", i);
        scanf("%d", &mas2[i]);
    }
}
void fill_mas3(int size3, int size1, int size2, int* mas1, int* mas2, int* mas3)
{
    for (int i = 0; i < size1; i++)
    {
        mas3[i] = mas1[i];
    }
    int j = 0;
    for (int i = size1; i < (size1 + size2); i++)
    {
        mas3[i] = mas2[j];
        j++;
    }

}

void sort_mas3(int size3,int* mas3)
{
    int temp;
    for (int i = (size3- 1);i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (mas3[j] > mas3[j+1])
            {
                temp = mas3[j];
                mas3[j] = mas3[j+1];
                mas3[j+1] = temp;
            }
        }
    }
}

void print_mas3(int* mas3, int size3)
{
    char  **result_buf = (char**)malloc(size3 * sizeof(char *));
    for(int i = 0; i < size3; i++)
    {
        result_buf[i] = (char *) malloc(12 * sizeof(char));
    }
    puts("result:");
    for(int i = 0; i < size3; i++)
    {
        sprintf(*(result_buf + i), " %d" , *(mas3 + i));
        fwrite(*(result_buf + i), sizeof(char), strlen(mas3) + 1, stdout);
    }
    free(result_buf);

}