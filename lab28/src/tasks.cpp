
#include "tasks.h"


Exersise::Exersise() : fileName(), ExersiseNumber(0), N(0), sizes(nullptr), arrays(nullptr), ResultSize(0), result(nullptr) {}

Exersise::~Exersise() {
    if (arrays)
        for (int i = 0; i < N; i++)
            delete[] arrays[i];
    delete[] arrays;
    delete[] sizes;
    delete[] result;
}

void Exersise::Run() {
    for (;;) {
        try {
            cout << "Enter Input FileName: ";
            ReadNameFile();
            if (fileName == "\\exit") // \\exit => "\exit"
                return;
            cout << "Reading... " <<endl;
            ReadFromFile();
            ExersiseNumber = Menu();
            CallingSelectedFunction(ExersiseNumber);
            cout << endl << "Enter Output FileName: ";
            ReadNameFile();
            if (fileName == "\\exit")
                return;
            cout << "Writing... " << endl;
            WriteToFile();
        }
        catch (out_of_range& e) {
            cout << " 1 " <<e.what() << endl;
        }
        catch (std::ios_base::failure& e) {
            cout << " 2 " <<e.what() << endl;
        }
        catch (std::invalid_argument& e) {
            cout << " 3 " <<e.what() << endl;
        }
        cout << endl << "-----------------------------------------" << endl << endl;
        system("pause&cls");
    }
}


void Exersise::ReadNameFile() {
    cin >> fileName;
}

void Exersise::ReadFromFile() {
    ifstream fin;
    fin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    fin.open(fileName, std::ios_base::in);
    fin >> N;
    if (N < 0) {
        throw std::invalid_argument("Bad Argument");
    }
    sizes = new int[N];
    arrays = new int*[N];
    for (int i = 0; i < N; i++) {
        int val_size;
        fin >> val_size;
        setSize(i, val_size);
        arrays[i] = new int[getSize(i)];
        for (int j = 0; j < getSize(i); j++)
        {
            int val;
            fin >> val;
            setElem(i, j, val);
        }
    }
    fin.close();
}

void Exersise:: WriteToFile() {
    ofstream fout;
    fout.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    fout.open(fileName, std::ios_base::out);
    for (int i = 0; i < ResultSize; i++){
        fout << result[i] << " ";
    }
    fout.close();
}

int Exersise:: getSize(int arrIndex) {
    if (arrIndex >= N || arrIndex < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        return sizes[arrIndex];
    }
}
int Exersise:: getElem(int arrIndex, int index) {
    if (arrIndex >= N || arrIndex < 0){
        throw out_of_range("Out of range exception");
    }
    else if (index >= sizes[arrIndex] || index < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        return arrays[arrIndex][index];
    }
}
void Exersise:: setSize(int arrIndex, int val) {
    if (arrIndex >= N || arrIndex < 0 || val < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        sizes[arrIndex] = val;
    }
}
void Exersise:: setElem(int arrIndex, int index, int val) {
    if (arrIndex >= N || arrIndex < 0 ){
        throw out_of_range("Out of range exception:");
    }
    else if (index >= sizes[arrIndex] || index < 0){
        throw out_of_range("Out of range exception");
    }
    else{
        arrays[arrIndex][index] = val;
    }
}

int* Exersise::SumArrays(int index1, int index2){
    if (getSize(index1) != getSize(index2)) {
        ResultSize = 0;
        result = nullptr;
        throw std::invalid_argument("Bad Argument");
    }
    ResultSize = getSize(index1);
    int *temp_res = new int[ResultSize];
    for (int i = 0; i < ResultSize; i++)
        temp_res[i] = getElem(index1, i) + getElem(index2, i);
    return temp_res;
}

int* Exersise::MultiplyArrays(int index1, int index2) {
    if (getSize(index1) != getSize(index2)) {
        ResultSize = 0;
        result = nullptr;
        throw std::invalid_argument("Bad Argument");
    }
    ResultSize = getSize(index1);
    int *temp_res = new int[ResultSize];
    for (int i = 0; i < ResultSize; i++)
        temp_res[i] = getElem(index1, i) * getElem(index2, i);
    return temp_res;
}

int* Exersise::CalcAverage() {
    int *temp_res = new int[N];
    int sum = 0;
    ResultSize = N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            sum += getElem(i, j);
        }
        temp_res[i] = sum / getSize(i);
        sum = 0;
    }
    return temp_res;
}

int* Exersise::FindMaxElem(){
    int *temp_res = new int[N];
    int elem = 0;
    ResultSize = N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem < getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        temp_res[i] = elem;
    }
    return temp_res;
}

int* Exersise::FindMinElem(){
    int *temp_res = new int[N];
    int elem = 0;
    ResultSize = N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem > getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        temp_res[i] = elem;
    }
    return temp_res;
}

int* Exersise::FindPositiveNumber() {
    int *temp_res = new int[N];
    int count = 0;
    ResultSize = N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if(getElem(i, j) >= 0){
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

int* Exersise::SearchInRange(int range1, int range2) {
    if(range1 >= range2){
        ResultSize = 0;
        result = nullptr;
        throw std::invalid_argument("Bad Argument");
    }
    int *temp_res = new int[N];
    int count = 0;
    ResultSize = N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if(getElem(i, j) >= range1 && getElem(i, j) <= range2) {
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

int* Exersise::FindNegativeNumber() {
    int *temp_res = new int[N];
    int count = 0;
    ResultSize = N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if(getElem(i, j) < 0){
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

int* Exersise::FindMaxElemPos(){
    int *temp_res = new int[N];
    int pos = 0;
    int elem = 0;
    ResultSize = N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem < getElem(i, j)){
                elem = getElem(i, j);
                pos = j;
            }
        }
        temp_res[i] = pos;
    }
    return temp_res;
}

int* Exersise::FindNMaxElem() {
    int *temp_res = new int[N];
    int elem = 0;
    int count = 0;
    ResultSize = N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < getSize(i); ++j) {
            if (j == 0 ){
                elem = getElem(i, j);
            }
            if(elem < getElem(i, j)){
                elem = getElem(i, j);
            }
        }
        for (int j = 0; j < getSize(i); ++j) {
            if(elem == getElem(i, j)){
                count++;
            }
        }
        temp_res[i] = count;
        count = 0;
    }
    return temp_res;
}

void Exersise::ForTest(int number){
    fileName = "test.txt";
    ExersiseNumber = number;
    ReadFromFile();
    CallingSelectedFunction(ExersiseNumber);
    fileName = "TestResult.txt";
    WriteToFile();
}
