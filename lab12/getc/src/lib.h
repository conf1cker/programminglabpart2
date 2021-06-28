
#pragma once
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#ifndef LAB12GETC_LIB_H
#define LAB12GETC_LIB_H
void fill_mas1(int size1, int *mas1);
void fill_mas2(int size2, int *mas2);
void fill_mas3(int size3,int size1,int size2, int* mas1, int* mas2, int* mas3);
void sort_mas3(int size3, int *mas3);
void print_mas3(int *mas3, int size3);
#endif //LAB12GETC_LIB_H
