

#ifndef LAB18_LIB_H
#define LAB18_LIB_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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




char *element_insert(char * text, char * pasted_text, int position);
char *element_edelet(char * text, int start_pos, int end_pos);

void read_from_textfile(struct Guitar **guitar);
void random_guitar_tunes(struct Guitar **guitar);
void Print_in_console(struct Guitar **guitar);


struct Guitar** Insert_struct (struct Guitar **guitar, struct Guitar *insert, int position);

struct Guitar** Delete_struct (struct Guitar **guitar, int position);



#endif //LAB18_LIB_H
