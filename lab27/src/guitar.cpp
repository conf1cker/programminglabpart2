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

// ---------------------------------------------Haslednik 1


AcousticGuitar::AcousticGuitar(): Guitar(), distance_between_decks(7), quantity(Six) {}

AcousticGuitar::AcousticGuitar(int pickup, string firm, int guitar_tunes , const Gitar_strings& strings, enum Guitar_size guitar_size ,
                               int distance_between_decks, enum  Number_of_strings quantity):pickup(pickup), firm(firm), guitar_tunes(guitar_tunes), strings(strings),  guitar_size(guitar_size),
                                                                                             distance_between_decks(distance_between_decks), quantity(quantity) {}


AcousticGuitar:: ~AcousticGuitar() = default;

int AcousticGuitar::getpickup() const
{
    return this->pickup;
}

string AcousticGuitar::getfirm() const
{
    return this->firm;
}

int AcousticGuitar::getguitar_tunes() const
{
    return this->guitar_tunes;
}

Gitar_strings AcousticGuitar::getstrings() const
{
    return this->strings;
}

Guitar_size AcousticGuitar::getguitar_size() const
{
    return this->guitar_size;
}


void AcousticGuitar::setpickup(const int pickup)
{
    this->pickup = pickup;
}

void AcousticGuitar::setfirm(const string firm)
{
    this->firm = firm;
}

void AcousticGuitar::setguitar_tunes(const int guitar_tunes)
{
    this->guitar_tunes = guitar_tunes;
}

void AcousticGuitar::setstrings(Gitar_strings *strings1)
{
    strings.setmin_string_thickness(strings1->getmin_string_thickness());
    strings.setmaterials(strings1->getmaterials());
}

void AcousticGuitar::setguitar_size(const Guitar_size guitar_size)
{
    this->guitar_size = guitar_size;
}

int AcousticGuitar ::getdistance_between_decks() const {
    return this->distance_between_decks;
}

Number_of_strings AcousticGuitar ::getquantity() const {
    return this-> quantity;
}


void AcousticGuitar ::setdistance_between_decks(const int distance_between_decks) {
    this->distance_between_decks = distance_between_decks;
}

void AcousticGuitar ::setquantity(const Number_of_strings quantity) {
    this-> quantity = quantity;
}

void AcousticGuitar::print()
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
    cout<<"растояние между деками: "<< distance_between_decks;
    cout<<"\n";
    cout<<"количество струн: "<< quantity;
    cout<<"\n";
}



Guitar* AcousticGuitar::clone() {
    return (Guitar*)new AcousticGuitar(*this);
}


// ----------------------------------Haslednik 2



ElectricGuitar::ElectricGuitar(): Guitar(), number_of_regulators(7), coppus(Stratocaster) {}

ElectricGuitar::ElectricGuitar(int pickup, string firm, int guitar_tunes , const Gitar_strings& strings, enum Guitar_size guitar_size ,
                               int number_of_regulators, enum  Coppus_shape coppus):pickup(pickup), firm(firm), guitar_tunes(guitar_tunes), strings(strings),  guitar_size(guitar_size),
                                                                                    number_of_regulators(number_of_regulators), coppus(coppus) {}



ElectricGuitar:: ~ElectricGuitar() = default;

int ElectricGuitar::getpickup() const
{
    return this->pickup;
}

string ElectricGuitar::getfirm() const
{
    return this->firm;
}

int ElectricGuitar::getguitar_tunes() const
{
    return this->guitar_tunes;
}

Gitar_strings ElectricGuitar::getstrings() const
{
    return this->strings;
}

Guitar_size ElectricGuitar::getguitar_size() const
{
    return this->guitar_size;
}


void ElectricGuitar::setpickup(const int pickup)
{
    this->pickup = pickup;
}

void ElectricGuitar::setfirm(const string firm)
{
    this->firm = firm;
}

void ElectricGuitar::setguitar_tunes(const int guitar_tunes)
{
    this->guitar_tunes = guitar_tunes;
}

void ElectricGuitar::setstrings(Gitar_strings *strings1)
{
    strings.setmin_string_thickness(strings1->getmin_string_thickness());
    strings.setmaterials(strings1->getmaterials());
}

void ElectricGuitar::setguitar_size(const Guitar_size guitar_size)
{
    this->guitar_size = guitar_size;
}

int ElectricGuitar ::getnumber_of_regulators() const {
    return this->number_of_regulators;
}

Coppus_shape ElectricGuitar ::getcoppus() const {
    return this-> coppus;
}


void ElectricGuitar ::setnumber_of_regulators(const int number_of_regulators) {
    this->number_of_regulators = number_of_regulators;
}

void ElectricGuitar ::setcoppus(const Coppus_shape coppus) {
    this-> coppus = coppus;
}

void ElectricGuitar::print()
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
    cout<<"количество регуляторов: "<< number_of_regulators;
    cout<<"\n";
    cout<<"форма корпуса: "<< coppus;
    cout<<"\n";
}



Guitar* ElectricGuitar::clone() {
    return (Guitar*)new ElectricGuitar(*this);
}
