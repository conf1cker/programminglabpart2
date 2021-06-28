

#ifndef LAB23_GUITAR_H
#define LAB23_GUITAR_H

#include <string>
#include <cstring>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;


enum Materials
{
    Synthetic,
    Stainless_steel,
    Gold,
    Steel_and_nicole,
    Bronze,
    Copper
};

class Gitar_strings
{
    int min_string_thickness;
    enum Materials materials;
public:
    Gitar_strings ();
    Gitar_strings (int  min_string_thickness,enum Materials materials );
    Gitar_strings(const Gitar_strings &copy);
    virtual ~Gitar_strings();

    int getmin_string_thickness() const;
    Materials getmaterials()const;

    void setmin_string_thickness(const int min_string_thickness);
    void setmaterials(const Materials materials);

    void print();
};

enum Guitar_size
{
    size = 1,
    size2 = 1/2,
    size3 = 1/4,
    size4 = 3/4
};


class Guitar
{
    bool pickup;//звукознимач
    string firm;
    int guitar_tunes;//количество ладов
    Gitar_strings strings;
    Guitar_size guitar_size;
public:
    Guitar();
    Guitar(int pickup, string firm, int guitar_tunes , const Gitar_strings& strings, enum Guitar_size guitar_size );
    Guitar(const Guitar &copy);
    virtual ~Guitar();

    int getpickup() const;
    string getfirm() const;
    int getguitar_tunes() const;
    Gitar_strings getstrings() const;
    Guitar_size getguitar_size() const;

    void setpickup(const int pickup);
    void setfirm(const string firm);
    void setguitar_tunes(const int guitar_tunes);
    void setstrings(Gitar_strings *strings1);
    void setguitar_size(const Guitar_size guitar_size);

    void print();


};


void PrintForm();




#endif //LAB23_GUITAR_H
