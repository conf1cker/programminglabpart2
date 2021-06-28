#include "list.h"




struct List *Creating_list()
{
    struct List *list = malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void Read_from_file(struct List* list)
{
    FILE *file = fopen("/home/sascha/Programing/lab19/guitar.txt", "r");
    if (file == NULL)
    {
        printf("can't open because: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < QUANTITY_STRUCT; i++){
        bool Pickup;
        char Firm[10];
        int Guitar_tunes;
        int Min_string_thickness;
        int materialS;
        int guitar_sizE;
        fscanf(file, "%u %s %u %u %u %u", &Pickup, Firm, &Guitar_tunes, &Min_string_thickness, &materialS, &guitar_sizE);
        add_element_end(list, Pickup , Firm , Guitar_tunes ,Min_string_thickness ,materialS, guitar_sizE);
    }
    fclose(file);
}


void add_element_end(struct List *list, bool Pickup , char Firm[10] , int Guitar_tunes ,int Min_string_thickness ,int materialS, int guitar_sizE)
{
    struct ListGuitar *guitar = fill_new_element_list(Pickup , Firm , Guitar_tunes ,Min_string_thickness ,materialS, guitar_sizE);

    guitar->prev = list->tail;
    if (list->tail) {
        list->tail->next = guitar;
    }else {
        list->head = guitar;
    }
    list->tail = guitar;
}


struct ListGuitar *fill_new_element_list(bool Pickup , char Firm[10] , int Guitar_tunes ,int Min_string_thickness ,int materialS, int guitar_sizE)
{
    struct ListGuitar *guitar = malloc(sizeof(struct ListGuitar));
    guitar->pickup = Pickup;
    strcpy(guitar->firm , Firm);
    guitar->guitar_tunes = Guitar_tunes;
    guitar->strings.min_string_thickness = Min_string_thickness;
    guitar->strings.materials = materialS;
    guitar->guitar_size = guitar_sizE;
    guitar->next = NULL;
    guitar->prev = NULL;
    return guitar;
}

void Print_from_console(struct List *list)
{
    for (struct ListGuitar *guitar = list->head; guitar != NULL; guitar = guitar->next)
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

void Write_from_file(struct List *list)
{
    FILE *file;
    file = fopen("/home/sascha/Programing/lab19/guitar_result.txt", "w");
    if (file == NULL)
    {
        printf("can't open because: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    for(struct ListGuitar *guitar = list->head; guitar != NULL; guitar = guitar->next)
    {
        if(guitar->pickup == true)
        {
            fprintf(file, "Availability of a pickup: Yes\n");
        }
        else
        {
            fprintf(file, "Availability of a pickup: NO\n");
        }
        fprintf(file, "Firma: %s\n", guitar->firm);
        fprintf(file, "Guitar_tunes :%u\n", guitar->guitar_tunes);
        fprintf(file, "Min_string_thickness : %u\n", guitar->strings.min_string_thickness);
        if(guitar->strings.materials == Synthetic)
        {
            fprintf(file,"The Guitar materials:  Synthetic\n");
        }
        else if(guitar->strings.materials == Stainless_steel)
        {
            fprintf(file,"The Guitar materials: Stainless_steel\n");
        }
        else if(guitar->strings.materials == Gold)
        {
            fprintf(file,"The Guitar materials: Gold \n");
        }
        else if(guitar->strings.materials == Steel_and_nicole)
        {
            fprintf(file,"The Guitar materials: Steel_and_nicole\n");
        }
        else if(guitar->strings.materials == Bronze)
        {
            fprintf(file,"The Guitar materials: Bronze\n");
        }
        else if(guitar->strings.materials == Copper)
        {
            fprintf(file,"The Guitar materials: Copper\n");
        }
        printf(file, "\n");
        ///////////
        if(guitar->guitar_size == size )
        {
            fprintf(file,"The Guitar size: %u\n", size);
        }
        else if(guitar->guitar_size == size2)
        {
            fprintf(guitar,"The Guitar size: %d\n", size2);
        }
        else if(guitar->guitar_size == size3)
        {
            fprintf(file,"The Guitar size: %d\n", size3);
        }
        else if(guitar->guitar_size == size4)
        {
            fprintf(file,"The Guitar size: %d\n", size4);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}


void Sort_by_criterion(struct List *list, int sort)
{
    if (sort == 1) {
        struct ListGuitar *left = list->head;
        struct ListGuitar *right = list->head->next;

        struct ListGuitar *temp = malloc(
                sizeof(struct ListGuitar));

        while (left->next)
        {
            while (right)
            {
                if ((left->guitar_tunes) < (right->guitar_tunes))
                {
                    temp->guitar_tunes = left->guitar_tunes;
                    left->guitar_tunes = right->guitar_tunes;
                    right->guitar_tunes = temp->guitar_tunes;
                }
                right = right->next;
            }
            left = left->next;
            right = left->next;
        }
    }
    else
    {
        struct ListGuitar *left = list->head;
        struct ListGuitar *right = list->head->next;

        struct ListGuitar *temp = malloc(
                sizeof(struct ListGuitar));

        while (left->next)
        {
            while (right)
            {
                if ((left->strings.min_string_thickness) < (right->strings.min_string_thickness)) {
                    temp->strings.min_string_thickness = left->strings.min_string_thickness;
                    left->strings.min_string_thickness = right->strings.min_string_thickness;
                    right->strings.min_string_thickness = temp->strings.min_string_thickness;
                }
                right = right->next;
            }
            left = left->next;
            right = left->next;
        }

    }
}

void Delete_element(struct List *list, int pos)
{
    if(pos < 0)
    {
        return;
    }
    struct ListGuitar *p = list->head;
    if(pos == 0)
    {
        if(!list->head)
        {
            return;
        }
        list->head = list->head->next;
        if(p->next)
        {
            p->next->prev = NULL;
        }else
        {
            list->tail = NULL;
        }
        free(p);
        return;
    }
    for(int i = pos; i > 0; i--)
    {
        if(!p)
        {
            return;
        }
        p = p->next;
    }
    p->prev->next = p->next;
    if(p->next)
    {
        p->next->prev = p->prev;
    }else
    {
        list->tail = p->prev;
    }
    free(p);
}


void Incert_element(struct List *list, int pos, bool Pickup , char Firm[10] , int Guitar_tunes ,int Min_string_thickness ,int materialS, int guitar_sizE)
{
    if(pos <= 0){
        Adde_lement_begin(list, Pickup , Firm , Guitar_tunes ,Min_string_thickness ,materialS, guitar_sizE);
        return;
    }
    struct ListGuitar *p = list->head;
    for(int i = pos; i > 0; i--){
        if(!p) {
            add_element_end(list, Pickup , Firm , Guitar_tunes ,Min_string_thickness ,materialS, guitar_sizE);
            return;
        }
        p = p->next;
    }
    struct ListGuitar * guitar = fill_new_element_list(Pickup , Firm , Guitar_tunes ,Min_string_thickness ,materialS, guitar_sizE);
    guitar->prev = p->prev;
    guitar->next = p;
    guitar->next->prev = guitar;
    guitar->prev->next = guitar;
}


void Adde_lement_begin(struct List *list, bool Pickup , char Firm[10] , int Guitar_tunes ,int Min_string_thickness ,int materialS, int guitar_sizE)
{
    struct ListGuitar *guitar = fill_new_element_list(Pickup , Firm , Guitar_tunes ,Min_string_thickness ,materialS, guitar_sizE);
    guitar->next = list->head;
    if(list->head){
        list->head->prev = guitar;
    }else{
        list->tail = guitar;
    }
    list->head = guitar;
}




void FreeList(struct List *list)
{
    while (list->head)
    {
        struct ListGuitar *p = list->head;
        list->head = p->next;
        free(p);
    }
    free(list);
}




