

#ifndef LAB19_LIST_H
#define LAB19_LIST_H


#include "guitar.h"



struct List
{
    struct  ListGuitar *head;
    struct  ListGuitar *tail;
};



struct List *Creating_list();

void Read_from_file(struct List* list);

void add_element_end(struct List *list, bool Pickup , char Firm[10] , int Guitar_tunes ,int Min_string_thickness ,int materialS, int guitar_sizE);

struct ListGuitar *fill_new_element_list(bool Pickup , char Firm[10] , int Guitar_tunes ,int Min_string_thickness ,int materialS, int guitar_sizE);

void Write_from_file(struct List *list);

void Print_from_console(struct List *list);

void Search_in_the_list();

void Delete_element(struct List *list, int pos);

void Sort_by_criterion(struct List *list, int sort);

void Incert_element(struct List *list, int pos, bool Pickup , char Firm[10] , int Guitar_tunes ,int Min_string_thickness ,int materialS, int guitar_sizE);

void Adde_lement_begin(struct List *list, bool Pickup , char Firm[10] , int Guitar_tunes ,int Min_string_thickness ,int materialS, int guitar_sizE);

void FreeList(struct List *list);

long currentTimeMillis();








#endif //LAB19_LIST_H
