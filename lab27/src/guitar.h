


#ifndef LAB27_GUITAR_H
#define LAB27_GUITAR_H


#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <regex>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;

#define SIZE 255

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

class Guitar{
public:
    virtual void print() = 0;
    virtual Guitar* clone() = 0;
    virtual ~Guitar() {}

};
enum Guitar_size
{
    size = 1,
    size2 = 1/2,
    size3 = 1/4,
    size4 = 3/4
};


//|--------------------Наследник 1--------------------|\\


enum Number_of_strings
{
    Six,Seven,Twelve
};


class AcousticGuitar : public Guitar
{
    bool pickup;//звукознимач
    string firm;
    int guitar_tunes;//количество ладов
    Gitar_strings strings;
    Guitar_size guitar_size;
    int distance_between_decks;
    Number_of_strings quantity;
public:
    AcousticGuitar();
    AcousticGuitar(int pickup, string firm, int guitar_tunes , const Gitar_strings& strings, enum Guitar_size guitar_size , int distance_between_decks, enum  Number_of_strings quantity);

    virtual ~AcousticGuitar();

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

    int getdistance_between_decks()const;
    Number_of_strings getquantity()const;

    void setdistance_between_decks(const int distance_between_decks);
    void setquantity(const Number_of_strings quantity);

    Guitar *clone() override;

    void print() ;


};

//|--------------------Наследник 2--------------------|\\

enum Coppus_shape
{
    Stratocaster, Super_start, Telecaster, Les_paul
};


class ElectricGuitar : public Guitar
{
    bool pickup;//звукознимач
    string firm;
    int guitar_tunes;//количество ладов
    Gitar_strings strings;
    Guitar_size guitar_size;
    int number_of_regulators;
    Coppus_shape coppus;
public:
    ElectricGuitar();
    ElectricGuitar(int pickup, string firm, int guitar_tunes , const Gitar_strings& strings, enum Guitar_size guitar_size , int number_of_regulators, enum  Coppus_shape coppus);

    virtual ~ElectricGuitar();

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


    int getnumber_of_regulators()const;
    Coppus_shape  getcoppus()const;

    void setnumber_of_regulators(const int distance_between_decks);
    void setcoppus(const Coppus_shape coppus);

    Guitar *clone() override;



    void print() ;


};

#endif //LAB27_GUITAR_H
