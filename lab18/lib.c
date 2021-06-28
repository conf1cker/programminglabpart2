#include "lib.h"


char *element_insert(char * text, char * pasted_text, int position){
    if(position < 0){
        position = 0;
    }
    if(position > strlen(text)){
        position = strlen(text);
    }
    char* new_text = malloc((strlen(text) + strlen(pasted_text))* sizeof (char));
    memcpy(new_text, text, position);
    memcpy(new_text + position, pasted_text, strlen(pasted_text));
    memcpy(new_text + position + strlen(pasted_text), text + position, strlen(text) - position);
    *(new_text + strlen(pasted_text) + strlen(text)) = '\0';
    return new_text;
}

char * element_edelet(char * text, int start_pos, int end_pos){
    if(start_pos < 0 && end_pos > 0){
        start_pos = 0;
    }
    if(start_pos < 0 && end_pos > strlen(text)){
        start_pos = 0;
        end_pos = strlen(text) - 1;
    }
    if(end_pos > strlen(text)){
        end_pos = strlen(text) - 1;
    }
    if(start_pos > end_pos){
        return "Error";
    } else if(start_pos > strlen(text) || end_pos < 0){
        return "Nothing to delete";
    }
    char* new_text = malloc((strlen(text) - (end_pos - start_pos))* sizeof (char));
    memcpy(new_text, text, start_pos);
    memcpy(new_text + start_pos, text + end_pos + 1, strlen(text) - end_pos);
    return  new_text;
}


void read_from_textfile(struct Guitar **guitar)
{
    FILE *file = fopen("/home/sascha/Programing/lab18/guitar.txt", "r");
    if (file == NULL)
    {
        printf("can't open because: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < QUANTITY_STRUCT; i++)
    {
        struct Guitar* temp = *(guitar + i);
        fscanf(file, "%u %s %u %u %u ", &(temp->pickup), (temp ->firm),  &(temp->strings.min_string_thickness), &(temp->strings.materials), &(temp ->guitar_size));
    }
    fclose(file);
}

void random_guitar_tunes(struct Guitar **guitar)
{
    for(int i = 0; i < QUANTITY_STRUCT; i++)
    {
        struct Guitar* temp = *(guitar + i);
        temp->guitar_tunes = rand() % 8 + 20;
    }

}

void Print_in_console(struct Guitar **guitar)
{
    for(int i = 0; i < QUANTITY_STRUCT; i++)
    {
        struct Guitar* temp = *(guitar + i);
        if(temp->pickup == true)
        {
            printf("Availability of a pickup: Yes\n");
        }
        else if(temp->pickup == false)
        {
            printf("Availability of a pickup: NO\n");
        }
        printf("Firma: %s\n", temp->firm);
        printf("Guitar_tunes :%u\n", temp->guitar_tunes);
        printf("Min_string_thickness : %u\n", temp->strings.min_string_thickness);
        if(temp->strings.materials == Synthetic)
        {
            printf("The Guitar materials:  Synthetic\n");
        }
        else if(temp->strings.materials == Stainless_steel)
        {
            printf("The Guitar materials: Stainless_steel\n");
        }
        else if(temp->strings.materials == Gold)
        {
            printf("The Guitar materials: Gold \n");
        }
        else if(temp->strings.materials == Steel_and_nicole)
        {
            printf("The Guitar materials: Steel_and_nicole\n");
        }
        else if(temp->strings.materials == Bronze)
        {
            printf("The Guitar materials: Bronze\n");
        }
        else if(temp->strings.materials == Copper)
        {
            printf("The Guitar materials: Copper\n");
        }
        ////////////
        if(temp->guitar_size == 0 )
        {
            printf("The Guitar size: 1\n");
        }
        else if(temp->guitar_size == 1)
        {
            printf("The Guitar size: 1/2\n");
        }
        else if(temp->guitar_size == 2)
        {
            printf("The Guitar size: 1/4\n");
        }
        else if(temp->guitar_size == 3)
        {
            printf("The Guitar size: 3/4\n");
        }
        printf("\n");
    }
}



struct Guitar** Insert_struct (struct Guitar **guitar, struct Guitar *insert, int position){
    struct Guitar ** result = malloc((QUANTITY_STRUCT + 1) * sizeof (struct Guitar));
    for(int i = 0; i < QUANTITY_STRUCT + 1; i++){
        *(result + i) = malloc(sizeof (struct Guitar));
    }
    if(position < 0){
        position = 0;
    }
    if(position >= QUANTITY_STRUCT){
        position = QUANTITY_STRUCT;
        memcpy(*result, *guitar, sizeof (struct Guitar) * (position + 1));
        memcpy(*(result + position), insert, sizeof (struct Guitar));
        memcpy(*(result + position + 1), *(guitar + position), sizeof (struct Guitar) * (QUANTITY_STRUCT - position));
    }else{
        memcpy(*result, *guitar, sizeof (struct Guitar) * (position));
        memcpy(*(result + position), insert, sizeof (struct Guitar));
        memcpy(*(result + position + 1), *(guitar + position), sizeof (struct Guitar) * (QUANTITY_STRUCT - position + 1));
    }
    printf("\nРезульат вставки:\n\n");
    QUANTITY_STRUCT + 1;
    Print_in_console(result);

    return result;
}

struct Guitar** Delete_struct (struct Guitar **guitar, int position){
    struct Guitar ** result = malloc((QUANTITY_STRUCT - 1) * sizeof (struct Guitar));
    for(int i = 0; i < QUANTITY_STRUCT - 1; i++){
        *(result + i) = malloc(sizeof (struct Guitar));
    }
    if(position < 0){
        position = 0;
    }
    if(position >= QUANTITY_STRUCT - 1) {
        position = QUANTITY_STRUCT;
    }
    memcpy(*result, *guitar, sizeof (struct Guitar) * (position + 1));
    memcpy(*(result + position), *(guitar + position + 1), sizeof (struct Guitar) * (QUANTITY_STRUCT - position));

    printf("\nРезульат удаления:\n\n");
    QUANTITY_STRUCT -1;
    Print_in_console(result);

    return result;
}


