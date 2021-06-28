

#ifndef RGZ_LIST_H
#define RGZ_LIST_H

#include "guitar.h"


class List
{
    vector<Guitar*> guitars;
    int index = -1;
public:

    /**
* Конструктор по умолчанию
*/
    List();


    /**
* Конструктор копирования
*/
    List(const List &copy);

    /**
        * Деструктор по умолчанию
        */
    virtual ~List();


    /**
* Метод добавления
*/

    void addGuitar(Guitar *guitar);

    /**
* Метод доступа по индексу
*/
    vector<Guitar*> getGuitar();

    /**
* Метод добавления по индексу
*/
    void setGuitar(vector<Guitar*> &guitar1);

    /**
* Метод печати
*/
    void showAll() const;

    /**
* Метод удаления по индексу
*/
    void DeleteElement(int index);

    /**
* Метод удаления
*/
    void DeleteAll();

};

#endif //RGZ_LIST_H
