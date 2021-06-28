

#include "guitar.h"
#include "list.h"

void Search_in_the_list(struct List *list, int index)
{
    bool Pickup;
    char Firm[10];
    int Guitar_tunes;
    int Min_string_thickness;
    int materialS;
    int guitar_sizE;
    int Availability;
    switch(index)
    {
        case 1:
            for (struct ListGuitar *guitar = list->head; guitar != NULL; guitar = guitar->next)
            {
                printf(" Присутствие 1 , отсутствие 0 ");
                scanf("%d", Pickup);
                printf("\n");
                if (guitar->pickup == Pickup)
                {
                    if(guitar->pickup == true)
                    {
                        printf("Availability of a pickup: Yes\n");
                    }
                    else if(guitar->pickup == false)
                    {
                        printf("Availability of a pickup: NO\n");
                    }
                    printf("Firma: %s\n", guitar->firm);
                    printf("Guitar_tunes :%u\n", guitar->guitar_tunes);
                    printf("Min_string_thickness : %u\n", guitar->strings.min_string_thickness);
                    if(guitar->strings.materials == Synthetic)
                    {
                        printf("The Guitar materials:  Synthetic\n");
                    }
                    else if(guitar->strings.materials == Stainless_steel)
                    {
                        printf("The Guitar materials: Stainless_steel\n");
                    }
                    else if(guitar->strings.materials == Gold)
                    {
                        printf("The Guitar materials: Gold \n");
                    }
                    else if(guitar->strings.materials == Steel_and_nicole)
                    {
                        printf("The Guitar materials: Steel_and_nicole\n");
                    }
                    else if(guitar->strings.materials == Bronze)
                    {
                        printf("The Guitar materials: Bronze\n");
                    }
                    else if(guitar->strings.materials == Copper)
                    {
                        printf("The Guitar materials: Copper\n");
                    }
                    ////////////
                    if(guitar->guitar_size == 0 )
                    {
                        printf("The Guitar size: 1\n");
                    }
                    else if(guitar->guitar_size == 1)
                    {
                        printf("The Guitar size: 1/2\n");
                    }
                    else if(guitar->guitar_size == 2)
                    {
                        printf("The Guitar size: 1/4\n");
                    }
                    else if(guitar->guitar_size == 3)
                    {
                        printf("The Guitar size: 3/4\n");
                    }
                    printf("\n");
                }

            }

            break;
        case 2:
            printf(" Введите фирму, которую нужно найти: ");
            scanf("%s", Firm);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct ListGuitar *guitar = list->head; guitar != NULL; guitar = guitar->next)
            {
                if (strcmp(guitar->firm, Firm) == 0)
                {
                    if(guitar->pickup == true)
                    {
                        printf("Availability of a pickup: Yes\n");
                    }
                    else if(guitar->pickup == false)
                    {
                        printf("Availability of a pickup: NO\n");
                    }
                    printf("Firma: %s\n", guitar->firm);
                    printf("Guitar_tunes :%u\n", guitar->guitar_tunes);
                    printf("Min_string_thickness : %u\n", guitar->strings.min_string_thickness);
                    if(guitar->strings.materials == Synthetic)
                    {
                        printf("The Guitar materials:  Synthetic\n");
                    }
                    else if(guitar->strings.materials == Stainless_steel)
                    {
                        printf("The Guitar materials: Stainless_steel\n");
                    }
                    else if(guitar->strings.materials == Gold)
                    {
                        printf("The Guitar materials: Gold \n");
                    }
                    else if(guitar->strings.materials == Steel_and_nicole)
                    {
                        printf("The Guitar materials: Steel_and_nicole\n");
                    }
                    else if(guitar->strings.materials == Bronze)
                    {
                        printf("The Guitar materials: Bronze\n");
                    }
                    else if(guitar->strings.materials == Copper)
                    {
                        printf("The Guitar materials: Copper\n");
                    }
                    ////////////
                    if(guitar->guitar_size == 0 )
                    {
                        printf("The Guitar size: 1\n");
                    }
                    else if(guitar->guitar_size == 1)
                    {
                        printf("The Guitar size: 1/2\n");
                    }
                    else if(guitar->guitar_size == 2)
                    {
                        printf("The Guitar size: 1/4\n");
                    }
                    else if(guitar->guitar_size == 3)
                    {
                        printf("The Guitar size: 3/4\n");
                    }
                    printf("\n");
                }


            }
            break;
        case 3:
            printf("Введите Guitar_tunes: ");
            scanf("%d", &Guitar_tunes);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct ListGuitar *guitar = list->head; guitar != NULL; guitar = guitar->next)
            {
                if (guitar->guitar_tunes == Guitar_tunes)
                {
                    if(guitar->pickup == true)
                    {
                        printf("Availability of a pickup: Yes\n");
                    }
                    else if(guitar->pickup == false)
                    {
                        printf("Availability of a pickup: NO\n");
                    }
                    printf("Firma: %s\n", guitar->firm);
                    printf("Guitar_tunes :%u\n", guitar->guitar_tunes);
                    printf("Min_string_thickness : %u\n", guitar->strings.min_string_thickness);
                    if(guitar->strings.materials == Synthetic)
                    {
                        printf("The Guitar materials:  Synthetic\n");
                    }
                    else if(guitar->strings.materials == Stainless_steel)
                    {
                        printf("The Guitar materials: Stainless_steel\n");
                    }
                    else if(guitar->strings.materials == Gold)
                    {
                        printf("The Guitar materials: Gold \n");
                    }
                    else if(guitar->strings.materials == Steel_and_nicole)
                    {
                        printf("The Guitar materials: Steel_and_nicole\n");
                    }
                    else if(guitar->strings.materials == Bronze)
                    {
                        printf("The Guitar materials: Bronze\n");
                    }
                    else if(guitar->strings.materials == Copper)
                    {
                        printf("The Guitar materials: Copper\n");
                    }
                    ////////////
                    if(guitar->guitar_size == 0 )
                    {
                        printf("The Guitar size: 1\n");
                    }
                    else if(guitar->guitar_size == 1)
                    {
                        printf("The Guitar size: 1/2\n");
                    }
                    else if(guitar->guitar_size == 2)
                    {
                        printf("The Guitar size: 1/4\n");
                    }
                    else if(guitar->guitar_size == 3)
                    {
                        printf("The Guitar size: 3/4\n");
                    }
                    printf("\n");

                }

            }
            break;
        case 4:
            printf(" Введите Min_string_thickness: ");
            scanf("%d", &Min_string_thickness);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct ListGuitar *guitar = list->head; guitar != NULL; guitar = guitar->next)
            {
                if (guitar->strings.min_string_thickness == Min_string_thickness)
                {
                    if(guitar->pickup == true)
                    {
                        printf("Availability of a pickup: Yes\n");
                    }
                    else if(guitar->pickup == false)
                    {
                        printf("Availability of a pickup: NO\n");
                    }
                    printf("Firma: %s\n", guitar->firm);
                    printf("Guitar_tunes :%u\n", guitar->guitar_tunes);
                    printf("Min_string_thickness : %u\n", guitar->strings.min_string_thickness);
                    if(guitar->strings.materials == Synthetic)
                    {
                        printf("The Guitar materials:  Synthetic\n");
                    }
                    else if(guitar->strings.materials == Stainless_steel)
                    {
                        printf("The Guitar materials: Stainless_steel\n");
                    }
                    else if(guitar->strings.materials == Gold)
                    {
                        printf("The Guitar materials: Gold \n");
                    }
                    else if(guitar->strings.materials == Steel_and_nicole)
                    {
                        printf("The Guitar materials: Steel_and_nicole\n");
                    }
                    else if(guitar->strings.materials == Bronze)
                    {
                        printf("The Guitar materials: Bronze\n");
                    }
                    else if(guitar->strings.materials == Copper)
                    {
                        printf("The Guitar materials: Copper\n");
                    }
                    ////////////
                    if(guitar->guitar_size == 0 )
                    {
                        printf("The Guitar size: 1\n");
                    }
                    else if(guitar->guitar_size == 1)
                    {
                        printf("The Guitar size: 1/2\n");
                    }
                    else if(guitar->guitar_size == 2)
                    {
                        printf("The Guitar size: 1/4\n");
                    }
                    else if(guitar->guitar_size == 3)
                    {
                        printf("The Guitar size: 3/4\n");
                    }
                    printf("\n");

                }

            }
            break;
        case 5:
            printf(" Введите materialS: ");
            scanf("%d", &materialS);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct ListGuitar *guitar = list->head; guitar != NULL; guitar = guitar->next)
            {
                if (guitar->strings.materials == materialS)
                {
                    if(guitar->pickup == true)
                    {
                        printf("Availability of a pickup: Yes\n");
                    }
                    else if(guitar->pickup == false)
                    {
                        printf("Availability of a pickup: NO\n");
                    }
                    printf("Firma: %s\n", guitar->firm);
                    printf("Guitar_tunes :%u\n", guitar->guitar_tunes);
                    printf("Min_string_thickness : %u\n", guitar->strings.min_string_thickness);
                    if(guitar->strings.materials == Synthetic)
                    {
                        printf("The Guitar materials:  Synthetic\n");
                    }
                    else if(guitar->strings.materials == Stainless_steel)
                    {
                        printf("The Guitar materials: Stainless_steel\n");
                    }
                    else if(guitar->strings.materials == Gold)
                    {
                        printf("The Guitar materials: Gold \n");
                    }
                    else if(guitar->strings.materials == Steel_and_nicole)
                    {
                        printf("The Guitar materials: Steel_and_nicole\n");
                    }
                    else if(guitar->strings.materials == Bronze)
                    {
                        printf("The Guitar materials: Bronze\n");
                    }
                    else if(guitar->strings.materials == Copper)
                    {
                        printf("The Guitar materials: Copper\n");
                    }
                    ////////////
                    if(guitar->guitar_size == 0 )
                    {
                        printf("The Guitar size: 1\n");
                    }
                    else if(guitar->guitar_size == 1)
                    {
                        printf("The Guitar size: 1/2\n");
                    }
                    else if(guitar->guitar_size == 2)
                    {
                        printf("The Guitar size: 1/4\n");
                    }
                    else if(guitar->guitar_size == 3)
                    {
                        printf("The Guitar size: 3/4\n");
                    }
                    printf("\n");

                }

            }
            break;
        case 6:
            printf("Введите guitar_sizE: ");
            scanf("%d", &guitar_sizE);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct ListGuitar *guitar = list->head; guitar != NULL; guitar = guitar->next)
            {
                if (guitar->guitar_size == guitar_sizE)
                {
                    if(guitar->pickup == true)
                    {
                        printf("Availability of a pickup: Yes\n");
                    }
                    else if(guitar->pickup == false)
                    {
                        printf("Availability of a pickup: NO\n");
                    }
                    printf("Firma: %s\n", guitar->firm);
                    printf("Guitar_tunes :%u\n", guitar->guitar_tunes);
                    printf("Min_string_thickness : %u\n", guitar->strings.min_string_thickness);
                    if(guitar->strings.materials == Synthetic)
                    {
                        printf("The Guitar materials:  Synthetic\n");
                    }
                    else if(guitar->strings.materials == Stainless_steel)
                    {
                        printf("The Guitar materials: Stainless_steel\n");
                    }
                    else if(guitar->strings.materials == Gold)
                    {
                        printf("The Guitar materials: Gold \n");
                    }
                    else if(guitar->strings.materials == Steel_and_nicole)
                    {
                        printf("The Guitar materials: Steel_and_nicole\n");
                    }
                    else if(guitar->strings.materials == Bronze)
                    {
                        printf("The Guitar materials: Bronze\n");
                    }
                    else if(guitar->strings.materials == Copper)
                    {
                        printf("The Guitar materials: Copper\n");
                    }
                    ////////////
                    if(guitar->guitar_size == 0 )
                    {
                        printf("The Guitar size: 1\n");
                    }
                    else if(guitar->guitar_size == 1)
                    {
                        printf("The Guitar size: 1/2\n");
                    }
                    else if(guitar->guitar_size == 2)
                    {
                        printf("The Guitar size: 1/4\n");
                    }
                    else if(guitar->guitar_size == 3)
                    {
                        printf("The Guitar size: 3/4\n");
                    }
                    printf("\n");

                }

            }
            break;
        default:
            printf("Некорректный вариант\n\n");
            Availability = 1;
            break;
    }

}

