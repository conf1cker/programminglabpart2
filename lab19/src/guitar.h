
#ifndef LAB19_GUITAR_H
#define LAB19_GUITAR_H


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



struct ListGuitar
{
    bool pickup;//звукознимач
    char firm[10];
    int guitar_tunes;//количество ладов
    struct gitar_strings strings;
    enum Guitar_size guitar_size;
    struct ListGuitar *next;
    struct ListGuitar *prev;

};








#endif //LAB19_GUITAR_H
