
#include "list.h"



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

    struct List *list = Creating_list();
    Read_from_file(list);

    for (int i = 0; i < 100; ++i)
    {
        int index;
        printf("***********ВАРИАНТЫ ДЕЙСТВИЙ***********\n");
        printf("1. Вывести список на экран\n");
        printf("2. Найти в списке элемент\n");
        printf("3. Удалить элемент из списка\n");
        printf("4. Сортировать список\n");
        printf("5. Вставить новый элемент в список\n");
        printf("6. Очистить список\n");
        printf("Другой символ: завершение програмы\n");
        printf(" **************************************\n");
        printf("Выберите действие: ");
        scanf("%d", &index);
        switch (index)
        {
            case 1:
                printf("Мой список");
                printf(" **************************************\n");
                Print_from_console(list);
                Write_from_file(list);
                printf(" **************************************\n");
                break;
            case 2:
                printf("Введите критерий по которому хотите найти гитару\n");
                printf("1. pickup\n");
                printf("2. firm\n");
                printf("3. guitar_tunes\n");
                printf("4. min_string_thickness\n");
                printf("5. materials\n");
                printf("6. guitar_size\n");
                int criterion;
                scanf("%d", &criterion);
                Search_in_the_list(list,criterion);
                break;
            case 3:
                printf("Введите индекс елемента, который удалить: ");
                int pos;
                scanf("%d", &pos);
                Delete_element(list,pos);
                //Print_from_console(list);
                break;
            case 4:
                printf("Введите критерий по которому хотите отсортировать список\n");
                printf("1. guitar_tunes\n");
                printf("2. min_string_thickness\n");
                int sort;
                scanf("%d", &sort);
                Sort_by_criterion(list, sort );
                printf("Список отсортировано");
                //Print_from_console(list);
                break;
            case 5:
                printf("Введите позицию куда вставить узел");
                int pos_insert;
                scanf("%u", &pos_insert);
                printf("Введите элементы вставляемого узла\n");
                printf("Введите Pickup 1-есть, 0-нет\n");
                bool Pickup;
                scanf("%u", &Pickup);
                printf("Введите фирму");
                char Firm[10];
                scanf("%s", Firm);
                printf("Введите Guitar_tunes");
                int Guitar_tunes;
                scanf("%u", &Guitar_tunes);
                printf("Введите Min_string_thickness");
                int Min_string_thickness;
                scanf("%u", &Min_string_thickness);
                printf("Введите materialS по счету из перечня");
                int materialS;
                scanf("%u", &materialS);
                printf("Введите guitar_sizE из перечня");
                int guitar_sizE;
                scanf("%u", &guitar_sizE);
                Incert_element(list, pos_insert, Pickup , Firm , Guitar_tunes ,Min_string_thickness ,materialS, guitar_sizE);
                break;
            case 6:
                FreeList(list);
                break;
            default:
                printf("Завершение роботы ");
                i =100;
        }


    }
    //FreeList(list);
#ifdef DEBUG
    time_t end = clock();
    double time_spent = (double)(end - begin)/ CLOCKS_PER_SEC;
    printf(" | Time spent executing the program: %lf second(s)\n", time_spent);
#endif
    return  0;
}

