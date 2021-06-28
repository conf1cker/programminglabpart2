
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

//---------------------------------------------lab24--------------------------------------------//

string Guitar::toString() const// заполнение строки из обекта
{
    stringstream result;
    result << getpickup() << " " << getfirm() << " " << getguitar_tunes() << " " << getstrings().getmin_string_thickness() << " "
           << getstrings().getmaterials() << " " << getguitar_size() << endl;


    cout << result.str() << endl;
    return result.str();
}


Guitar&  Guitar::convert_string_to_object( const string &obj_str) const //Разбитие строки на переменные и заполнение полей
{
    stringstream Result(obj_str);
    int Pickup;
    string Firm;
    int Tunes;
    int min_string;
    auto *temp = new Guitar;
    string mater;
    int siZe;

    Result >> Pickup >> Firm >> Tunes >> min_string >> mater >> siZe;
//    cout<<Pickup;
//    cout<<Firm;
//    cout<<Tunes;
//    cout<<min_string;
//    cout<<mater;
//    cout<<siZe;
//
    const int pickuP = Pickup;

    temp->setpickup(pickuP);
    temp->setfirm(Firm);
    temp->setguitar_tunes(Tunes);
    temp->setguitar_size(size);

    auto *strings = new Gitar_strings;

    strings->setmin_string_thickness(min_string);
    strings->setmaterials(Stainless_steel);
    temp->setstrings(strings);
    return *temp;
}

// lab 25


Guitar& Guitar::operator=(const Guitar &guitar)
{
    if(this != &guitar)
    {
        setpickup(guitar.getpickup());
        setfirm(guitar.getfirm());
        setguitar_tunes(guitar.getguitar_tunes());
        Gitar_strings gitar_strings(guitar.getstrings().getmin_string_thickness(), guitar.getstrings().getmaterials()) ;
        setstrings(&gitar_strings);
        setguitar_size(guitar.getguitar_size());

    }
    return *this;
}

bool operator==(const Guitar& A, const Guitar& B)
{
    bool result = true;
    if(A.getpickup() == B.getpickup() && A.getfirm() == B.getfirm() && A.getguitar_tunes() == B.getguitar_tunes()
       && A.getstrings().getmin_string_thickness() == B.getstrings().getmin_string_thickness() && A.getstrings().getmaterials() == B.getstrings().getmaterials()
       && A.getguitar_size() == B.getguitar_size())
    {
        result &= true;
    }
    else
    {
        result &= false;
    }
    return result;
}

ostream & operator<<(ostream &out ,const Guitar& guitar)
{
    cout<<"Pickup: "<<guitar.getpickup();
    cout<<"\n";
    cout<<"Firm: "<<guitar.getfirm();
    cout<<"\n";
    cout<<"guitar_tunes: "<<guitar.getguitar_tunes();
    cout<<"\n";
    cout<< "min_string_thickness: "<< guitar.getstrings().getmin_string_thickness();
    cout<<"\n";
    cout<<"materials: "<< guitar.getstrings().getmaterials();
    cout<<"\n";
    cout<<"guitar_size: "<<guitar.getguitar_size();
    cout<<"\n";
    cout<<"\n";

}

istream & operator>>(istream &in, Guitar& guitar)
{

    int Pickup;
    string Firm;
    int Tunes;
    int min_string;
    string mater;
    int siZe;

    in >> Pickup;
    in  >> Firm;
    in >> Tunes;
    in >> min_string;
    in >> mater;
    in >> siZe;


    guitar.setpickup(Pickup);
    guitar.setfirm(Firm);
    guitar.setguitar_tunes(Tunes);
    guitar.setguitar_size(size);

    Gitar_strings gitar_strings (min_string, Steel_and_nicole);
    guitar.setstrings(&gitar_strings);

}
// lab 26

 //Haslednik 1


AcousticGuitar::AcousticGuitar(): Guitar(), distance_between_decks(7), quantity(Six) {}

AcousticGuitar::AcousticGuitar(int pickup, string firm, int guitar_tunes , const Gitar_strings& strings, enum Guitar_size guitar_size ,
        int distance_between_decks, enum  Number_of_strings quantity):Guitar(pickup, firm, guitar_tunes, strings,  guitar_size),
                distance_between_decks(distance_between_decks), quantity(quantity) {}

AcousticGuitar::AcousticGuitar(AcousticGuitar& copy) : Guitar(copy.getpickup(), copy.getfirm() ,copy.getguitar_tunes(), copy.getstrings(), copy.getguitar_size()),
distance_between_decks(copy.distance_between_decks) , quantity(copy.quantity){}

AcousticGuitar:: ~AcousticGuitar() = default;

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
    Guitar::print();
    cout<<"растояние между деками: "<< distance_between_decks;
    cout<<"\n";
    cout<<"количество струн: "<< quantity;
    cout<<"\n";
}

// Haslednik 2



ElectricGuitar::ElectricGuitar(): Guitar(), number_of_regulators(7), coppus(Stratocaster) {}

ElectricGuitar::ElectricGuitar(int pickup, string firm, int guitar_tunes , const Gitar_strings& strings, enum Guitar_size guitar_size ,
                               int number_of_regulators, enum  Coppus_shape coppus):Guitar(pickup, firm, guitar_tunes, strings,  guitar_size),
                                                                                             number_of_regulators(number_of_regulators), coppus(coppus) {}

ElectricGuitar::ElectricGuitar(ElectricGuitar& copy) : Guitar(copy.getpickup(), copy.getfirm() ,copy.getguitar_tunes(), copy.getstrings(), copy.getguitar_size()),
                                                       number_of_regulators(copy.number_of_regulators) , coppus(copy.coppus){}

ElectricGuitar:: ~ElectricGuitar() = default;

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
    Guitar::print();
    cout<<"количество регуляторов: "<< number_of_regulators;
    cout<<"\n";
    cout<<"форма корпуса: "<< coppus;
    cout<<"\n";
}
