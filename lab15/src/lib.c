#include "lib.h"
void read_from_textfile(struct Guitar **guitar)
{
    FILE *file = fopen("guitar.txt", "r");
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

void Print_in_file(struct Guitar **guitar)
{
    FILE *file;
    file = fopen("Result_guitar.txt", "w");
    if (file == NULL)
    {
        printf("can't open because: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < QUANTITY_STRUCT; i++)
    {
        struct Guitar* temp = *(guitar + i);
        if(temp->pickup == true)
        {
            fprintf(file, "Availability of a pickup: Yes\n");
        }
        else
        {
            fprintf(file, "Availability of a pickup: NO\n");
        }
        fprintf(file, "Firma: %s\n", temp->firm);
        fprintf(file, "Guitar_tunes :%u\n", temp->guitar_tunes);
        fprintf(file, "Min_string_thickness : %u\n", temp->strings.min_string_thickness);
        if(temp->strings.materials == Synthetic)
        {
            fprintf(file,"The Guitar materials:  Synthetic\n");
        }
        else if(temp->strings.materials == Stainless_steel)
        {
            fprintf(file,"The Guitar materials: Stainless_steel\n");
        }
        else if(temp->strings.materials == Gold)
        {
            fprintf(file,"The Guitar materials: Gold \n");
        }
        else if(temp->strings.materials == Steel_and_nicole)
        {
            fprintf(file,"The Guitar materials: Steel_and_nicole\n");
        }
        else if(temp->strings.materials == Bronze)
        {
            fprintf(file,"The Guitar materials: Bronze\n");
        }
        else if(temp->strings.materials == Copper)
        {
            fprintf(file,"The Guitar materials: Copper\n");
        }
        printf(file, "\n");
        ///////////
        if(temp->guitar_size == size )
        {
            fprintf(file,"The Guitar size: %u\n", size);
        }
        else if(temp->guitar_size == size2)
        {
            fprintf(file,"The Guitar size: %d\n", size2);
        }
        else if(temp->guitar_size == size3)
        {
            fprintf(file,"The Guitar size: %d\n", size3);
        }
        else if(temp->guitar_size == size4)
        {
            fprintf(file,"The Guitar size: %d\n", size4);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void Sort_struct_by_criterion(struct Guitar **guitar, char criterion[10], int method)
{
    char tunes[10] = "tunes";
    char thickness[10] = "thickness";
    if (strcmp(tunes,criterion) == 0)
    {
        if(method == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < (3 -1); j++)
                {
                    if((*(guitar + j))->guitar_tunes > (*(guitar + j+1))->guitar_tunes)
                    {
                        struct Guitar *temp = *(guitar + j);
                        *(guitar + j) = *(guitar + j+1);
                        *(guitar + j+1) = temp;
                    }
                }
            }
        }
        else if( method == -1)
        {
            for (int i = 0; i < QUANTITY_STRUCT; i++)
            {
                for (int j = 0; j < (QUANTITY_STRUCT -1); j++)
                {
                    if((*(guitar + j))->guitar_tunes < (*(guitar + j+1))->guitar_tunes)
                    {
                        struct Guitar *temp = *(guitar + j);
                        *(guitar + j) = *(guitar + j+1);
                        *(guitar + j+1) = temp;
                    }
                }
            }

        }
    }
    else if(strcmp(thickness, criterion) == 0)
    {
        if(method == 1)
        {
            for (int i = 0; i < QUANTITY_STRUCT; i++)
            {
                for (int j = 0; j < (QUANTITY_STRUCT -1); j++)
                {
                    if((*(guitar + j))->strings.min_string_thickness > (*(guitar + j+1))->strings.min_string_thickness)
                    {
                        struct Guitar *temp = *(guitar + j);
                        *(guitar + j) = *(guitar + j+1);
                        *(guitar + j+1) = temp;
                    }
                }
            }
        }
        else if( method == -1)
        {
            for (int i = 0; i < QUANTITY_STRUCT; i++)
            {
                for (int j = 0; j < (QUANTITY_STRUCT -1); j++)
                {
                    if((*(guitar + j))->strings.min_string_thickness < (*(guitar + j+1))->strings.min_string_thickness)
                    {
                        struct Guitar *temp = *(guitar + j);
                        *(guitar + j) = *(guitar + j+1);
                        *(guitar + j+1) = temp;
                    }
                }
            }

        }
    }

}

void collection_method_number_1(struct Guitar **guitar)
{
    printf("\n\n");
    printf("Metod Koeleczii\n");
    for (int i = 0; i < QUANTITY_STRUCT; i++ )
    {
        if ( (*(guitar + i))->pickup == 1 &&  (*(guitar + i))->strings.min_string_thickness > 9)
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


}