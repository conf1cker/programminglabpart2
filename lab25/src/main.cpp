#include "list.h"


int main()
{
    auto *strings = new Gitar_strings;

    List * list = new List;
    string path = "/home/programminglabpart2/lab24/guitar.txt";
    list->ReadFromFile(path);



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


    list->addGuitar(*guitar);
    list->addGuitar(guitar1);
    list->addGuitar(guitar2);
    list->addGuitar(guitar3);

//-------------------------lab 25------------------------------------------------

    //Ввод списка(перегразка ввода/вывода списка) ++
    cin >> *list;

    cout << *list;

    //Перегрузка оператора = +++
    Guitar guitar5;
    guitar5.operator=(list->operator[](3));
    guitar5.print();

    //Перегрузка операторов сравнения == +++
    bool  result;
    if (list->getGuitar(1) == list->getGuitar(2)){
        result = true;
    } else{
        result = false;
    }
    cout <<result;


    //Перегрузка операторов ввода/вывода для базового класса +++
    Guitar guitar;
    cin >> guitar;

    cout << guitar;


//------------------------lab 24---------------------------------------------

    //cout << "----------------------------------Создание строки из объекта----------------------------------" << endl;
    //Объект представленый в строке
    //string test = list->getGuitar(4).toString();
    list->ShowAll();
    //list->getGuitar(4).print();
    //cout << endl << "> Information about the object in the line: " << test;
    //cout << "|-----------------------------------------------------------------------------------------------------|" << endl;
    //cout << endl;


    //cout << "----------------------------------Создание объекта из строки----------------------------------" << endl;

    //string obj = "1 Tomson 23 8 Stainless_steel size";
    //cout << endl << ">The string from which to get the object: " << obj << endl << endl;
    //Guitar *test1 = &test1->convert_string_to_object(obj);
    //test1->print();
    //list->addGuitar(*test1);
    //cout << "-----------------------------------------------------------------------------------------------------|" << endl;
    //cout << endl;


//---------------------------lab 23-----------------------------------------------------------------


    //cout << "Place for pickup( 1 - Yes, 0 - No)           " << endl << endl;
    //cout << "--------------------------------------------Оригинальный список--------------------------------------------" << endl;
    //Исходный список

    //list->ShowAll();
    //cout << "-----------------------------------------------------------------------------------------------------" << endl;
    //cout << endl;

    //cout << "----------------------------------------Метод колекции----------------------------------------" << endl;

    //list->Colektion_Guitar();
    //cout << "-----------------------------------------------------------------------------------------------------" << endl;
    //cout << endl;

    //cout << "-------------------------------------Получение по индуксу-------------------------------------" << endl;
    //Полученый элемент из списка
    //Guitar temp = list->getGuitar(1);

    //temp.print();
    //cout << "-----------------------------------------------------------------------------------------------------" << endl;
    //cout << endl;

    //cout << "-------------------------------Удаление по индексу-------------------------------" << endl;
    //Удаление элемента по индексу
    //list->removeGuitar(2);

    //list->ShowAll();
    //cout << "-----------------------------------------------------------------------------------------------------" << endl;
    //cout << endl;


     path = "/home/sascha/Programing/lab25/guitar_result.txt";
    list->WriteToFile(path);

    delete test1;
    delete  list;
    delete strings;
    delete guitar;
    return 0;


}
