#include "lib.h"


int main()
{
    char* text1 = malloc(sizeof (char)* 255);
    char* passed_text = malloc(sizeof (char)* 255);
    char* text2 = malloc(sizeof (char)* 255);

    printf("Введите текст: ");
    scanf("%s", text1);
    printf("Введите вставляемую строку: ");
    scanf("%s", passed_text);
    int position;
    printf("Введите позицию, после которой вставить строку: ");
    scanf("%i", &position);
    char* result_insert = element_insert(text1, passed_text, position);
    printf("Результат добавления: %s\n\n", result_insert);

    int start_pos;
    int end_pos;
    printf("Введите текст: \n");
    scanf("%s", text2);
    printf("Введите начальную позицию для удаления: ");
    scanf("%d", &start_pos);
    printf("Введите конечную позицию для удаления: ");
    scanf("%d", &end_pos);
    char* result_deleting = element_edelet(text2, start_pos, end_pos);
    printf("Результат удаления: %s\n\n", result_deleting);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct Guitar ** guitar = malloc(QUANTITY_STRUCT * sizeof (struct Guitar));
    for(int i = 0; i < QUANTITY_STRUCT; i++)
    {
        *(guitar + i) = malloc(sizeof (struct Guitar));
    }

    read_from_textfile(guitar);
    random_guitar_tunes(guitar);
    //Print_in_console(guitar);

    struct Guitar * insert = malloc(sizeof (struct Guitar));


    insert->pickup=1;
    strcpy(insert->firm, "Takamine");
    insert->guitar_tunes = 21;
    insert->strings.min_string_thickness = 8;
    insert->strings.materials = 5 ;
    insert->guitar_size= 1;

    printf("Вставляемая структура:\n\n");
    printf("Availability of a pickup: Yes\n");
    printf("Firm: %s\n", insert->firm);
    printf("Guitar_tunes %u\n", insert->guitar_tunes);
    printf("Min_string_thickness %u\n",insert->strings.min_string_thickness);
    printf("Strings.materials %u\n",  insert->strings.materials);
    printf("Guitar_size=1 %u\n",1);
    printf("\n");

    int pos_insert;
    printf("Введите позицию, на которую вставить структуру: ");
    scanf("%i", &pos_insert);

    Insert_struct(guitar, insert, pos_insert);

//    printf("\nМассив структур:\n\n");
//    Print_in_console(guitar);

    int pos_delete;
    printf("Введите позицию, после которой удалить структуру: ");
    scanf("%i", &pos_delete);

    Delete_struct(guitar, pos_delete);



    free(result_insert);
    free(text1);
    free(passed_text);
    free(result_deleting);
    free(text2);
    free(insert);
    for (int  i = 0; i < QUANTITY_STRUCT; i ++){
        free(*(guitar + i));
    }




    return 0;
}