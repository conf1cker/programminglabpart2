#include "../src/list.h"
//#include "../src/guitar.h"

bool Test_sort()
{
#ifdef DEBUG
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "Текущее время и дата: %s", asctime (timeinfo) );
    printf ( "Тест сортировки  \n");
#endif
    bool result = true;

    struct List *list = Creating_list();

    add_element_end(list, 1, "Fender", 19, 8, 0, 1);
    add_element_end(list, 0, "Gibson", 20, 12, 1, 0);
    add_element_end(list, 1, "Crafter", 21, 9, 0, 0);
    //tunes
    Sort_by_criterion(list, 1);

    int expected_tunes[3] = {21 ,20 ,19};
    if (expected_tunes[0] == list->head->guitar_tunes && expected_tunes[1] == list->head->next->guitar_tunes && expected_tunes[2] == list->head->next->next->guitar_tunes) {
        printf("Test passed!\n");
    }
    else {
        printf("Test failed!\n");
        result = false;
    }
}


bool Test_insert()
{
#ifdef DEBUG
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "Текущее время и дата: %s", asctime (timeinfo) );
    printf ( "Тест вставки  \n");
#endif
    bool result = true;

    struct List *list = Creating_list();

    add_element_end(list, 1, "Fender", 19, 8, 0, 1);
    add_element_end(list, 0, "Gibson", 20, 12, 1, 0);
    add_element_end(list, 1, "Crafter", 21, 9, 0, 0);

    Incert_element(list,1, 1, "11365478",  20, 8, 0, 1);
    if (!strcmp("11365478", list->head->next->firm))
    {
        printf("Test passed!\n");
    }
    else
    {
        printf("Test failed!\n");
        result = false;

    }

}


bool Test_delete()
{
#ifdef DEBUG
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "Текущее время и дата: %s", asctime (timeinfo) );
    printf ( "Тест удаления  \n");
#endif
    bool result = true;

    struct List *list = Creating_list();

    add_element_end(list, 1, "Fender", 19, 8, 0, 1);
    add_element_end(list, 0, "Gibson", 20, 12, 1, 0);
    add_element_end(list, 1, "Crafter", 21, 9, 0, 0);

    Delete_element(list,1);
    if (!strcmp("Crafter", list->head->next->firm))
    {
        printf("Test passed!\n");
    }
    else
    {
        printf("Test failed!\n");
        result = false;

    }
}


int main()
{
#ifdef DEBUG
    time_t begin = clock();
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "Текущее время и дата: %s", asctime (timeinfo) );
#endif
    printf("Тест сортировки\n");
    bool result = true;
    result &= Test_sort();
    //--------------------------------------------------
    printf("Тест вставки\n");
    result &= Test_insert();
    //************************
    //--------------------------------------------------
    printf("Тест удаления\n");
    result &= Test_delete();
    //************************
    if (result == true){
        printf("Все тесты успешны\n");
    }else{
        printf("D'oh");
    }
#ifdef DEBUG
    time_t end = clock();
    double time_spent = (double)(end - begin)/ CLOCKS_PER_SEC;
    printf(" Время работы програмы: %lf second(s)\n", time_spent);
#endif
}
