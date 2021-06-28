//
// Created by sascha on 08.06.2021.
//

#ifndef RGZ_GUITAR_H
#define RGZ_GUITAR_H

#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::stoi;
using std::vector;
using std::map;
using std::set;
using std::find_if;
using std::copy;
using std::sort;
using std::back_inserter;
using std::stringstream;



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
    /**
 * Конструктор по умолчанию
 */
    Gitar_strings ();
    /**
* Конструктор с параметрами
*/
    Gitar_strings (int  min_string_thickness,enum Materials materials );
    /**
* Конструктор копирования
*/

    Gitar_strings(const Gitar_strings &copy);
    /**
 * Деструктор по умолчанию
 */
    virtual ~Gitar_strings();
    /**
* Геттер толшины струны
*/

    int getmin_string_thickness() const;
    /**
* Геттер материала
*/
    Materials getmaterials()const;
    /**
      * Сеттер минимальной струны
      */
    void setmin_string_thickness(const int min_string_thickness);
    /**
   * Сеттер материала
   */
    void setmaterials(const Materials materials);

    void print();
};

class Guitar{
public:
    virtual void print() = 0;
    virtual Guitar* clone() = 0;
    virtual ~Guitar() {}
    virtual char GetType() = 0;

};

enum Guitar_size
{
    size = 1,
    size2 = 1/2,
    size3 = 1/4,
    size4 = 3/4
};



enum Number_of_strings
{
    Six,Seven,Twelve
};


class AcousticGuitar : public Guitar
{
    bool pickup;//звукознимач
    string firm;
    int guitar_tunes;//количество ладов
    Gitar_strings gitar_strings ;
    Guitar_size guitar_size;
    int distance_between_decks;
    Number_of_strings quantity;
public:
    /**
* Конструктор по умолчанию
*/
    AcousticGuitar();
    /**
* Конструктор с параметрами
*/
    AcousticGuitar(int pickup, string firm, int guitar_tunes , const Gitar_strings& strings, enum Guitar_size guitar_size , int distance_between_decks, enum  Number_of_strings quantity);

    /**
* Деструктор по умолчанию
*/
    virtual ~AcousticGuitar();

    /**
* Геттер звукосчитывателя
*/
    int getpickup() const;
    /**
  * Геттер фирмы
  */
    string getfirm() const;
    /**
 * Геттер количества ладов
 */
    int getguitar_tunes() const;
    /**
  * Геттер струны
  */
    Gitar_strings getstrings() const;
    /**
  * Геттер размера
  */
    Guitar_size getguitar_size() const;

    /**
   * Сеттер звукосчитывателя
   */
    void setpickup(const int pickup);
    /**
   * Сеттер фирмы
   */
    void setfirm(const string firm);
    /**
   * Сеттер количества ладов
   */
    void setguitar_tunes(const int guitar_tunes);
    /**
   * Сеттер струны
   */
    void setstrings(Gitar_strings *strings1);
    /**
   * Сеттер размера
   */
    void setguitar_size(const Guitar_size guitar_size);

    /**
* Геттер растояния между деками
*/
    int getdistance_between_decks()const;
    /**
 * Геттер растояния между деками
 */
    Number_of_strings getquantity()const;

    /**
   * Сеттер растояния между деками
   */
    void setdistance_between_decks(const int distance_between_decks);
    /**
   * Сеттер количества струн
   */
    void setquantity(const Number_of_strings quantity);

    Guitar *clone() override;

    void print() override;

    char GetType() override;


};



bool operator==(const AcousticGuitar& A, const AcousticGuitar&  B);


ostream & operator<<(ostream &out, const AcousticGuitar& guitar);


istream & operator>>(istream &in, AcousticGuitar& guitar);



enum Coppus_shape
{
    Stratocaster, Super_start, Telecaster, Les_paul
};


class ElectricGuitar : public Guitar
{
    bool pickup;//звукознимач
    string firm;
    int guitar_tunes;//количество ладов
    Gitar_strings gitar_strings;
    Guitar_size guitar_size;
    int number_of_regulators;
    Coppus_shape coppus;
public:
    /**
* Конструктор по умолчанию
*/
    ElectricGuitar();
    /**
* Конструктор с параметрами
*/
    ElectricGuitar(int pickup, string firm, int guitar_tunes , const Gitar_strings& strings, enum Guitar_size guitar_size , int number_of_regulators, enum  Coppus_shape coppus);

    /**
* Деструкторпо умолчанию
*/
    virtual ~ElectricGuitar();

    /**
  * Геттер звукосчитывателя
  */
    int getpickup() const;
    /**
  * Геттер фирмы
  */
    string getfirm() const;
    /**
 * Геттер количества ладов
 */
    int getguitar_tunes() const;
    /**
  * Геттер струны
  */
    Gitar_strings getstrings() const;
    /**
  * Геттер размера
  */
    Guitar_size getguitar_size() const;

    /**
   * Сеттер звукосчитывателя
   */
    void setpickup(const int pickup);
    /**
   * Сеттер фирмы
   */
    void setfirm(const string firm);
    /**
   * Сеттер количества ладов
   */
    void setguitar_tunes(const int guitar_tunes);
    /**
   * Сеттер струны
   */
    void setstrings(Gitar_strings *strings1);
    /**
   * Сеттер размера
   */
    void setguitar_size(const Guitar_size guitar_size);



    /**
* Геттер количества регуляторов
*/
    int getnumber_of_regulators()const;
    /**
  * Геттер вида корпуса
  */
    Coppus_shape  getcoppus()const;

    /**
   * Сеттер количества регуляторов
   */
    void setnumber_of_regulators(const int distance_between_decks);
    /**
   * Сеттер вида корпуса
   */
    void setcoppus(const Coppus_shape coppus);
    Guitar *clone() override;


    void print() override;

    char GetType() override;


};

bool operator==(const ElectricGuitar& A, const ElectricGuitar&  B);


ostream & operator<<(ostream &out, const ElectricGuitar& guitar);


istream & operator>>(istream &in, ElectricGuitar& guitar);


#endif //RGZ_GUITAR_H
