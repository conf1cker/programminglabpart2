
#ifndef LAB27_LIST_H
#define LAB27_LIST_H


#include "guitar.h"

class List{
    Guitar *guitar[SIZE];
    int index = -1;
public:
    List();
    List(const List &copy);

    virtual ~List();

    void addGuirar( Guitar * guitar);

    Guitar* getGuirar (int index) const;

    void ShowAll() const;


    List & operator=( const List &copy);

};





#endif //LAB27_LIST_H
