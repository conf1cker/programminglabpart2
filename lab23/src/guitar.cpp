#include "guitar.h"

//----------------------------Strings----------------------------------//

Gitar_strings :: Gitar_strings() : min_string_thickness() , materials()
{
  cout << "\ndefault constructor <Gitar_strings> " << endl;
}

Gitar_strings :: Gitar_strings(int min_string_thickness, enum Materials materials): min_string_thickness(min_string_thickness), materials(materials)
{
    cout << "\nConstructor with arguments <Gitar_strings> " << endl;
}

Gitar_strings::Gitar_strings(const Gitar_strings &copy):  min_string_thickness(copy.min_string_thickness), materials(copy.materials)
{
    cout << "\nCopy constructor <Gitar_strings> " << endl;
}

Gitar_strings ::~ Gitar_strings() = default;
{
    cout << "\nDestructor <Firm>" << endl;
}


int Gitar_strings::getmin_string_thickness() const
{
    return this->min_string_thickness;
}

Materials Gitar_strings::getmaterials() const
{
    return this->materials;
}

void Gitar_strings::setmin_string_thickness(const int min_string_thickness)
{
     this->min_string_thickness = min_string_thickness;
}

void Gitar_strings::setmaterials(const Materials materials)
{
    this->materials = materials;
}

void Gitar_strings::print()
{
    cout<<"min_string_thickness: "<<min_string_thickness;
    cout<<"\n";
    cout<<"materials: "<<materials;
    cout<<"\n";
}

//------------------------Guitar---------------------------//

Guitar::Guitar() : pickup(true), firm(), guitar_tunes(0), strings(), guitar_size(size)
{
    cout << "\ndefault constructor <Guitar> " << endl;
}

Guitar::Guitar(int pickup, string firm, int guitar_tunes, const Gitar_strings &strings, enum Guitar_size guitar_size) :
        pickup(pickup), firm(firm), guitar_tunes(guitar_tunes), strings(strings), guitar_size(guitar_size)
{
     cout << "\nConstructor with arguments <Guitar>" << endl;
}

Guitar::Guitar(const Guitar &copy) : pickup(copy.pickup), firm(copy.firm), guitar_tunes(copy.guitar_tunes),
                            strings(copy.strings), guitar_size(copy.guitar_size)
{
    cout << "\nCopy constructor <Guitar>" << endl;
}

Guitar:: ~Guitar()  = default;
{
cout << "\nDestructor <Backpack>" << endl;
}

int Guitar::getpickup() const
{
    return this->pickup;
}

string Guitar::getfirm() const
{
    return this->firm;
}

int Guitar::getguitar_tunes() const
{
    return this->guitar_tunes;
}

Gitar_strings Guitar::getstrings() const
{
    return this->strings;
}

Guitar_size Guitar::getguitar_size() const
{
    return this->guitar_size;
}


void Guitar::setpickup(const int pickup)
{
     this->pickup = pickup;
}

void Guitar::setfirm(const string firm)
{
     this->firm = firm;
}

void Guitar::setguitar_tunes(const int guitar_tunes)
{
     this->guitar_tunes = guitar_tunes;
}

void Guitar::setstrings(Gitar_strings *strings1)
{
    strings.setmin_string_thickness(strings1->getmin_string_thickness());
    strings.setmaterials(strings1->getmaterials());
}

void Guitar::setguitar_size(const Guitar_size guitar_size)
{
    this->guitar_size = guitar_size;
}

void Guitar::print()
{
    cout<<"Pickup: "<<pickup;
    cout<<"\n";
    cout<<"Firm: "<<firm;
    cout<<"\n";
    cout<<"guitar_tunes: "<<guitar_tunes;
    cout<<"\n";
    strings.print();
    cout<<"guitar_size: "<<guitar_size;
    cout<<"\n";
    cout<<"\n";
}











