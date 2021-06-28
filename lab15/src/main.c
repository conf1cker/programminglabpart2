#include "lib.h"

int main()
{
    int method;
    printf("%s\n", "Read data from text file");
    printf("\n");
    struct Guitar ** guitar = malloc(QUANTITY_STRUCT * sizeof (struct Guitar));
    for(int i = 0; i < QUANTITY_STRUCT; i++)
    {
        *(guitar + i) = malloc(sizeof (struct Guitar));
    }
    read_from_textfile(guitar);
    random_guitar_tunes(guitar);
    Print_in_console(guitar);
    char criterion[10];
    printf(" Введите критерий по какому будет проходить сортировка : tunes или thickness\n");
    scanf("%s", criterion );
    printf("\n");
    printf(" Введите вид сортировки : 1 по возростанию -1 по убыванию\n");
    scanf("%u", &method );
    printf("\n");
    Sort_struct_by_criterion(guitar, criterion, method);
    Print_in_console(guitar);
    Print_in_file(guitar);
    collection_method_number_1(guitar);
    return 0;
}
