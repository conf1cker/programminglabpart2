
#ifndef LAB15_LIB_H
#define LAB15_LIB_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>



#define QUANTITY_STRUCT 5

enum Materials
{
    Synthetic,
    Stainless_steel,
    Gold,
    Steel_and_nicole,
    Bronze,
    Copper
};

struct gitar_strings
{
    int min_string_thickness;
    enum  Materials materials;
};

enum Guitar_size
{
    size = 1,
    size2 = 1/2,
    size3 = 1/4,
    size4 = 3/4
};



struct Guitar
{
    bool pickup;//звукознимач
    char firm[10];
    int guitar_tunes;//количество ладов
    struct gitar_strings strings;
    enum Guitar_size guitar_size;

};


void read_from_textfile(struct Guitar ** name);
void random_guitar_tunes(struct Guitar **name);
void Sort_struct_by_criterion(struct Guitar **name, char criterion[10], int method);
void Print_in_console(struct Guitar **name);
void Print_in_file(struct Guitar **name);
void collection_method_number_1(struct Guitar **name);


#endif //LAB15_LIB_H
