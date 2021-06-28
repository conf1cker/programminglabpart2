
#ifndef INC_28_EXERSISE_H
#define INC_28_EXERSISE_H


#include "menu.h"




class Exersise {
    string fileName;
    int ExersiseNumber;
    int N;
    int* sizes;
    int** arrays;
    int ResultSize;
    int *result;
public:
    Exersise();
    ~Exersise();
    void Run();
    void ReadNameFile();
    void ReadFromFile();
    void WriteToFile();
    int getSize(int arrIndex);
    int getElem(int arrIndex, int index);
    void setSize(int arrIndex, int val);
    void setElem(int arrIndex, int index, int val);
    void CallingSelectedFunction(int number);
    int* SumArrays(int index1, int index2);
    int* MultiplyArrays(int index1, int index2);
    int* CalcAverage();
    int* FindMaxElem();
    int* FindMinElem();
    int* FindPositiveNumber();
    int* SearchInRange(int range1, int range2);
    int* FindNegativeNumber();
    int* FindMaxElemPos();
    int* FindNMaxElem();
    void ForTest(int number);
};

#endif //INC_28_EXERSISE_H
