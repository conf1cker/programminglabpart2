
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
                               int distance_between_decks, enum  Number_of_strings quantity):pickup(pickup), firm(firm), guitar_tunes(guitar_tunes), gitar_strings(gitar_strings),  guitar_size(guitar_size),
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
    return this->gitar_strings;
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
    gitar_strings.setmin_string_thickness(strings1->getmin_string_thickness());
    gitar_strings.setmaterials(strings1->getmaterials());
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
    gitar_strings.print();
    cout<<"guitar_size: "<<guitar_size;
    cout<<"\n";
    cout<<"растояние между деками: "<< distance_between_decks;
    cout<<"\n";
    cout<<"количество струн: "<< quantity;
    cout<<"\n";
    cout<<"\n";
}



Guitar* AcousticGuitar::clone() {
    return (Guitar*)new AcousticGuitar(*this);
}

char AcousticGuitar::GetType() {
    return 'A';
}

ostream & operator<<(ostream &out, AcousticGuitar& guitar){
    out << "     ";
    out << guitar.getpickup();
    out << "     ";
    out << guitar.getfirm();
    out << "     ";
    out << guitar.getguitar_tunes();
    out << "     ";
    out << guitar.getstrings().getmin_string_thickness();
    out << "     ";
    out << guitar.getstrings().getmaterials();
    out << "     ";
    out << guitar.getguitar_size() << endl;
    out << "     ";
    out << guitar.getdistance_between_decks();
    out << "     ";
    out << guitar.getquantity();
    return out;

}

istream & operator>>(istream &in, AcousticGuitar& guitar){
    char type;
    int pickup;
    int guitar_tunes;
    string firm;
    int min_string_thickness;
    int materials;
    int guitar_size;

    int distance_between_decks;
    int quantity;
    cout << "pickup: " << endl;
    in >> pickup;
    cout << "firm: " << endl;
    in >> firm;
    cout << "guitar_tunes: " << endl;
    in >> guitar_tunes;
    cout << "min_string_thickness: " << endl;
    in >> min_string_thickness;
    cout << "materials: " << endl;
    in >> materials;
    cout << "guitar_size: " << endl;
    in >> guitar_size;
    cout << "distance_between_decks: " << endl;
    in >> distance_between_decks;
    cout << "quantity: " << endl;
    in >> quantity;



    guitar.setpickup(pickup);
    guitar.setfirm(firm);
    guitar.setguitar_tunes(guitar_tunes);
    if (materials == 0) {
        Gitar_strings gitar_strings(min_string_thickness, Synthetic);
        guitar.setstrings(&gitar_strings);
    }
    else if(materials == 1){
        Gitar_strings gitar_strings1(min_string_thickness,Stainless_steel);
        guitar.setstrings(&gitar_strings1);
    }
    else if(materials == 2){
        Gitar_strings gitar_strings2(min_string_thickness,Gold);
        guitar.setstrings(&gitar_strings2);
    }
    else if(materials == 3){
        Gitar_strings gitar_strings3(min_string_thickness,Steel_and_nicole);
        guitar.setstrings(&gitar_strings3);
    }
    else if(materials == 4){
        Gitar_strings gitar_strings4(min_string_thickness,Bronze);
        guitar.setstrings(&gitar_strings4);
    }
    else if(materials == 5){
        Gitar_strings gitar_strings5(min_string_thickness,Copper);
        guitar.setstrings(&gitar_strings5);
    }

    if (guitar_size == 0) guitar.setguitar_size(size);
    else if (guitar_size == 1) guitar.setguitar_size(size2);
    else if (guitar_size == 2) guitar.setguitar_size(size3);
    else if (guitar_size == 3) guitar.setguitar_size(size4);

    guitar.setdistance_between_decks(distance_between_decks);
    if (quantity == 0) guitar.setquantity(Six);
    else if (quantity == 1) guitar.setquantity(Seven);
    else if (quantity == 2) guitar.setquantity(Twelve);

    return in;
}

bool operator==(const AcousticGuitar& A, const AcousticGuitar&  B){

    bool result = true;
    if(A.getpickup() == B.getpickup()
    &&A.getguitar_tunes() == B.getguitar_tunes()
      &&A.getfirm() == B.getfirm()
        &&A.getstrings().getmin_string_thickness() == B.getstrings().getmin_string_thickness()
          &&A.getstrings().getmaterials() == B.getstrings().getmaterials()
            &&A.getguitar_size() == B.getguitar_size()
              &&A.getdistance_between_decks() == B.getdistance_between_decks()
                &&A.getquantity() == B.getquantity()){
    result &= true;
    }else{
    result &= false;
    }
    return result;
}

// ----------------------------------Haslednik 2



ElectricGuitar::ElectricGuitar(): Guitar(), number_of_regulators(7), coppus(Stratocaster) {}

ElectricGuitar::ElectricGuitar(int pickup, string firm, int guitar_tunes , const Gitar_strings& strings, enum Guitar_size guitar_size ,
                               int number_of_regulators, enum  Coppus_shape coppus):pickup(pickup), firm(firm), guitar_tunes(guitar_tunes), gitar_strings(gitar_strings),  guitar_size(guitar_size),
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
    return this->gitar_strings;
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
    gitar_strings.setmin_string_thickness(strings1->getmin_string_thickness());
    gitar_strings.setmaterials(strings1->getmaterials());
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
    gitar_strings.print();
    cout<<"guitar_size: "<<guitar_size;
    cout<<"\n";
    cout<<"количество регуляторов: "<< number_of_regulators;
    cout<<"\n";
    cout<<"форма корпуса: "<< coppus;
    cout<<"\n";
    cout<<"\n";
}



Guitar* ElectricGuitar::clone() {
    return (Guitar*)new ElectricGuitar(*this);
}

char ElectricGuitar::GetType() {
    return 'E';
}

ostream & operator<<(ostream &out, const ElectricGuitar& guitar){
    out << "     ";
    out << guitar.getpickup();
    out << "     ";
    out << guitar.getfirm();
    out << "     ";
    out << guitar.getguitar_tunes();
    out << "     ";
    out << guitar.getstrings().getmin_string_thickness();
    out << "     ";
    out << guitar.getstrings().getmaterials();
    out << "     ";
    out << guitar.getguitar_size() << endl;
    out << "     ";
    out << guitar.getnumber_of_regulators();
    out << "     ";
    out << guitar.getcoppus();
    return out;
}

istream & operator>>(istream &in, ElectricGuitar& guitar)
{
    char type;
    int pickup;
    int guitar_tunes;
    string firm;
    int min_string_thickness;
    int materials;
    int guitar_size;

    int number_of_regulators;
    int coppus;
    cout << "pickup: " << endl;
    in >> pickup;
    cout << "firm: " << endl;
    in >> firm;
    cout << "guitar_tunes: " << endl;
    in >> guitar_tunes;
    cout << "min_string_thickness: " << endl;
    in >> min_string_thickness;
    cout << "materials: " << endl;
    in >> materials;
    cout << "guitar_size: " << endl;
    in >> guitar_size;
    cout << "number_of_regulators: " << endl;
    in >> number_of_regulators;
    cout << "quantity: " << endl;
    in >> coppus;



    guitar.setpickup(pickup);
    guitar.setfirm(firm);
    guitar.setguitar_tunes(guitar_tunes);
    if (materials == 0) {
        Gitar_strings gitar_strings(min_string_thickness, Synthetic);
        guitar.setstrings(&gitar_strings);
    }
    else if(materials == 1){
        Gitar_strings gitar_strings1(min_string_thickness,Stainless_steel);
        guitar.setstrings(&gitar_strings1);
    }
    else if(materials == 2){
        Gitar_strings gitar_strings2(min_string_thickness,Gold);
        guitar.setstrings(&gitar_strings2);
    }
    else if(materials == 3){
        Gitar_strings gitar_strings3(min_string_thickness,Steel_and_nicole);
        guitar.setstrings(&gitar_strings3);
    }
    else if(materials == 4){
        Gitar_strings gitar_strings4(min_string_thickness,Bronze);
        guitar.setstrings(&gitar_strings4);
    }
    else if(materials == 5){
        Gitar_strings gitar_strings5(min_string_thickness,Copper);
        guitar.setstrings(&gitar_strings5);
    }

    if (guitar_size == 0) guitar.setguitar_size(size);
    else if (guitar_size == 1) guitar.setguitar_size(size2);
    else if (guitar_size == 2) guitar.setguitar_size(size3);
    else if (guitar_size == 3) guitar.setguitar_size(size4);

    guitar.setnumber_of_regulators(number_of_regulators);

    if (guitar_size == 0) guitar.setcoppus(Stratocaster);
    else if (guitar_size == 1) guitar.setcoppus(Super_start);
    else if (guitar_size == 2) guitar.setcoppus(Telecaster);
    else if (guitar_size == 3) guitar.setcoppus(Les_paul);
    return  in;

}

bool operator==(const ElectricGuitar& A, const ElectricGuitar&  B){

    bool result = true;
    if(A.getpickup() == B.getpickup()
       &&A.getguitar_tunes() == B.getguitar_tunes()
       &&A.getfirm() == B.getfirm()
       &&A.getstrings().getmin_string_thickness() == B.getstrings().getmin_string_thickness()
       &&A.getstrings().getmaterials() == B.getstrings().getmaterials()
       &&A.getguitar_size() == B.getguitar_size()
       &&A.getnumber_of_regulators() == B.getnumber_of_regulators()
       &&A.getcoppus() == B.getcoppus()){
        result &= true;
    }else{
        result &= false;
    }
    return result;
}

