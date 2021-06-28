
#ifndef LAB23_LIST_H
#define LAB23_LIST_H

#include "guitar.h"



class List
{
    Guitar **guitar;
    size_t Count;
public:
    virtual ~List();
    void setCount(const int count);

    size_t getcount() const;

    void addGuitar( Guitar& guitar);
    void removeGuitar( int index);
    Guitar& getGuitar (int index) const;
    void ShowAll() const;
    Guitar& Colektion_Guitar() const;
    Guitar& convert_string_to_object(const string &object) const;


    void ReadFromFile(const string &path) ;
    void WriteToFile(const string &path);

    Guitar& operator[](const size_t index) const;

    void Print();

    friend ostream& operator<< (ostream &out, const List &list);
    friend istream& operator>> (istream &in, List &list);

    friend ofstream& operator<< (ofstream &out, const List &list);
    friend ifstream& operator>> (ifstream &in, List &list);

};













#endif //LAB23_LIST_H
