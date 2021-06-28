#ifndef UNTITLED1_LIB_H
#define UNTITLED1_LIB_H
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <errno.h>





void struct_folder(char *directory_name, int count_of_space);

double calculate_directory_size(char *directory_name);

void print_size_of_directory();

long int calculate_file_size(FILE *file);



#endif //UNTITLED1_LIB_H