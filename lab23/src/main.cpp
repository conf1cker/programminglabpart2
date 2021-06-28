#include "list.h"


int main()
{
    auto *strings = new Gitar_strings;

    strings->setmin_string_thickness(8);
    strings->setmaterials(Synthetic);

    auto *guitar = new Guitar;
    guitar->setpickup(true);
    guitar->setfirm("Fender");
    guitar->setguitar_tunes(19);
    guitar->setstrings(strings);
    guitar->setguitar_size(size);

    Guitar guitar1(true, "Yamaha", 19, Gitar_strings(9, Stainless_steel),size  );
    Guitar guitar2(false, "Cort", 20, Gitar_strings(9, Bronze), size2);
    Guitar guitar3(true, "Jackson", 21, Gitar_strings(11, Copper), size4);

    List * list = new List;
    list->addGuitar(*guitar);
    list->addGuitar(guitar1);
    list->addGuitar(guitar2);
    list->addGuitar(guitar3);


    cout << "Place for pickup 1 - Yes, 0 - No           " << endl << endl;
    cout << "--------------------------------------------Исходный список--------------------------------------------" << endl;
    //Исходный список

    list->ShowAll();
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "----------------------------------------Метод колекции----------------------------------------" << endl;

    list->Colektion_Guitar();
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "-------------------------------------Получение по индексу-------------------------------------" << endl;
    //Полученый элемент из списка
    Guitar temp = list->getGuitar(1);

    temp.print();
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "|-------------------------------Удаление по индексу-------------------------------|" << endl;
    //Удаление элемента по индексу
    list->removeGuitar(2);

    list->ShowAll();
    cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    cout << endl;



    delete  list;
    delete strings;
    delete guitar;
    return 0;


}
