

#ifndef LAB26_LIST_H
#define LAB26_LIST_H
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
//         Наследник 1
class ListAcousticGuitar
{
    AcousticGuitar **AcousticGuitars;
    size_t Count;
public:
    ListAcousticGuitar();

    ListAcousticGuitar(const ListAcousticGuitar &copy);

    virtual ~ListAcousticGuitar();

    void setCount(const int count);

    AcousticGuitar& getAcousticGuitar (int index) const;

    void  addGuitar( AcousticGuitar& guitar);

    virtual void ShowAll() const;

    AcousticGuitar& Colektion_Guitar() const;

};

//         Наследник 2

class ListElectricGuitar
{
    ElectricGuitar **ElectricGuitars;
    size_t Count;
public:
    ListElectricGuitar();

    ListElectricGuitar(const ListElectricGuitar &copy);

    virtual ~ListElectricGuitar();

    void setCount(const int count);

    ElectricGuitar& getElectricGuitar (int index) const;

    void  addGuitar( ElectricGuitar& guitar);

    virtual void ShowAll() const;

    ElectricGuitar& Colektion_Guitar() const;

    ElectricGuitar& Colektion_Guitar2() const;


};


#endif //LAB26_LIST_H
