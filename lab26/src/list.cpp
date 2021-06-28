
#include "list.h"


void List::setCount(const int count)
{
    this->Count = count;
}


List::~List()
{
    cout << "\nDestructor <List>" << endl;
    for (int i = 0; i < this->Count; ++i)
    {
        delete this->guitar[i];
    }
    delete[] guitar;
}

void List::addGuitar(Guitar& guitar)
{
    auto **temp = new Guitar*[this->Count + 1];
    cout << Count;
    for (int i = 0; i < this->Count; ++i)
    {
     
        temp[i] = this->guitar[i];
    }
    temp[Count] = &guitar;
    delete [] this->guitar;
    this->guitar = temp;
    this->Count +=1;
}


void List::removeGuitar(int index)
{
    auto **temp = new Guitar*[this->Count - 1];

    if(index < 0){
        index= 0;
    }
    if(index >= this->Count) {
        index = this->Count - 1;
    }

    memcpy(temp, guitar, sizeof (Guitar) * (index));
    memcpy(temp + index, guitar + index + 1, sizeof (Guitar) * (Count - index));

    delete [] this->guitar;
    this->guitar = temp;
    this->Count -= 1;
}

Guitar& List::getGuitar(int index) const
{
    if(index < 0){
        index= 0;
    }
    if(index >= this->Count) {
        index = this->Count - 1;
    }

    return *guitar[index];
}

void List::ShowAll() const
{
    for (int i = 0; i < this->Count; ++i) {
        Guitar temp = getGuitar(i);
        temp.print();
    }
}


Guitar& List::Colektion_Guitar() const
{
    int min_string_thickness = 9;
    bool pickup = 1;
    int index = -1;
    for (int i = 0; i < this->Count; ++i)
    {
        Guitar temp = getGuitar(i);
        if(min_string_thickness == temp.getstrings().getmin_string_thickness() && pickup == temp.getpickup())
        {
            temp.print();
            index = i;
        }
    }
    if (index == -1)
    {
        cout << "Нужная гитара не найдена" << endl;
        return getGuitar(0);
    } else
    {
        return getGuitar(index);
    }
}


void List::Print() {
    for (int i = 0; i < this->Count; ++i) {
        Guitar *temp = this->guitar[i];
        temp->print();
    }
}


void List::ReadFromFile(const string &path) {

    ifstream fin;
    fin.open(path);
    string obj;

    this->setCount(6);
    delete [] this->guitar;
    this->guitar = new Guitar*[Count];
    for (int i = 0; i < Count; ++i) {
        if (!fin.is_open()) {
            cout << "ERROR: The file did not open!" << endl;
        } else {
            getline(fin, obj);
            this->guitar[i] = &this->convert_string_to_object(obj);
        }
    }
    //this->ShowAll();

    fin.close();
}


void List::WriteToFile(const string &path) {

    ofstream output_file(path);
    if (!output_file.is_open())
    {
        cout << "ERROR: The file did not open!" << endl;
    }
    else
    {
        for (int i = 0; i < Count; ++i)
        {
            output_file << this->getGuitar(i).toString();
        }
    }
    output_file.close();
}


Guitar&  List::convert_string_to_object( const string &obj_str) const //Разбитие строки на переменные и заполнение полей
{
    string result = obj_str ;

    stringstream Result(obj_str);
    int Pickup;
    string Firm;
    int Tunes;
    int min_string;
    auto *temp = new Guitar;
    string mater;
    int siZe;

    Result >> Pickup >> Firm >> Tunes >> min_string >> mater >> siZe;
    cout<<Pickup;
    cout<<Firm;
    cout<<Tunes;
    cout<<min_string;
    cout<<mater;
    cout<<siZe;

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
}// lab 25

size_t List::getcount() const {
    return this->Count;
}

Guitar& List::operator[](const size_t index) const{
    if (index < Count)
    {
        return *guitar[index];
    } else
    {
        return *guitar[0];
    }
}

istream& operator>> (istream &in, List &list)
{
    int count;
    cout << "Enter count of object: " << endl;
    cin >> count;
    list.setCount(count);
    list.guitar = new Guitar*[count];
    for (int i = 0; i < count; ++i)
    {
        list.guitar[i] = new Guitar;
    }
    for (int i = 0; i < count; ++i)
    {
        cin >> list[i];
    }
    return in;
}

ostream & operator<<(ostream &out ,const List& list){
    for (int i = 0; i < list.getcount(); ++i) {
        out << list[i];
    }
    return out;
}

ofstream & operator<<(ofstream &out ,const List& list) {
    for (int i = 0; i < list.getcount(); ++i) {
        out << list[i];
    }
    return out;
}


// lab 26
// -----------------Haslednik 1

ListAcousticGuitar::ListAcousticGuitar() : AcousticGuitars(nullptr), Count(0) {}

ListAcousticGuitar::ListAcousticGuitar(const ListAcousticGuitar &copy): Count(copy.Count) {
    AcousticGuitars = new AcousticGuitar*[Count];
    for (int i = 0; i < Count; ++i) {
        AcousticGuitars[i] = new AcousticGuitar(*copy.AcousticGuitars[i]);
    }
}

ListAcousticGuitar:: ~ListAcousticGuitar() {
    for (int i = 0; i < Count; ++i) {
        delete AcousticGuitars[i];
    }
    delete [] AcousticGuitars;
}

void  ListAcousticGuitar::setCount(const int count){
    this->Count = count;
}

AcousticGuitar& ListAcousticGuitar::getAcousticGuitar(int index) const{
    if (index < Count){
        return *AcousticGuitars[index];
    } else{
        return *AcousticGuitars[0];
    }
}

void  ListAcousticGuitar::addGuitar( AcousticGuitar& guitar){
    auto **temp = new AcousticGuitar*[Count + 1];
    for (int i = 0; i < Count; ++i) {
        temp[i] = AcousticGuitars[i];
    }
    temp[Count] = &guitar;
    delete [] this->AcousticGuitars;
    this->AcousticGuitars = temp;
    this->Count++;
}

void ListAcousticGuitar::ShowAll() const{
    for (int i = 0; i < this->Count; ++i) {
        AcousticGuitar temp = getAcousticGuitar(i);
        temp.print();
        cout << endl;
    }
}

AcousticGuitar& ListAcousticGuitar::Colektion_Guitar() const
{
    int min_string_thickness = 9;
    bool pickup = 1;
    int index = -1;
    for (int i = 0; i < this->Count; ++i)
    {
        Guitar temp = getAcousticGuitar(i);
        if(min_string_thickness == temp.getstrings().getmin_string_thickness() && pickup == temp.getpickup())
        {
            temp.print();
            index = i;
        }
    }
    if (index == -1)
    {
        cout << "Нужная гитара не найдена" << endl;
        return getAcousticGuitar(0);
    } else
    {
        return getAcousticGuitar(index);
    }
}



// --------------------------------------Haslednik 2


ListElectricGuitar::ListElectricGuitar() : ElectricGuitars(nullptr), Count(0) {}

ListElectricGuitar::ListElectricGuitar(const ListElectricGuitar &copy): Count(copy.Count) {
    ElectricGuitars = new ElectricGuitar*[Count];
    for (int i = 0; i < Count; ++i) {
        ElectricGuitars[i] = new ElectricGuitar(*copy.ElectricGuitars[i]);
    }
}

ListElectricGuitar:: ~ListElectricGuitar() {
    for (int i = 0; i < Count; ++i) {
        delete ElectricGuitars[i];
    }
    delete [] ElectricGuitars;
}

void  ListElectricGuitar::setCount(const int count){
    this->Count = count;
}

ElectricGuitar& ListElectricGuitar::getElectricGuitar(int index) const{
    if (index < Count){
        return *ElectricGuitars[index];
    } else{
        return *ElectricGuitars[0];
    }
}

void  ListElectricGuitar::addGuitar( ElectricGuitar& guitar){
    auto **temp = new ElectricGuitar*[Count + 1];
    for (int i = 0; i < Count; ++i) {
        temp[i] = ElectricGuitars[i];
    }
    temp[Count] = &guitar;
    delete [] this->ElectricGuitars;
    this->ElectricGuitars = temp;
    this->Count++;
}

void ListElectricGuitar::ShowAll() const{
    for (int i = 0; i < this->Count; ++i) {
        ElectricGuitar temp = getElectricGuitar(i);
        temp.print();
        cout << endl;
    }
}

ElectricGuitar& ListElectricGuitar::Colektion_Guitar() const
{
    int min_string_thickness = 9;
    bool pickup = 1;
    int index = -1;
    for (int i = 0; i < this->Count; ++i)
    {
        Guitar temp = getElectricGuitar(i);
        if(min_string_thickness == temp.getstrings().getmin_string_thickness() && pickup == temp.getpickup())
        {
            temp.print();
            index = i;
        }
    }
    if (index == -1)
    {
        cout << "Нужная гитара не найдена" << endl;
        return getElectricGuitar(0);
    } else
    {
        return getElectricGuitar(index);
    }
}

ElectricGuitar& ListElectricGuitar::Colektion_Guitar2() const{
    string firm = "Fender";
    int tunes = 27;
    int index = -1;
    for (int i = 0; i < this->Count; ++i) {
        Guitar temp = getElectricGuitar(i);
        if(firm == temp.getfirm() && tunes == temp.getguitar_tunes())
        {
            temp.print();
            index = i;
        }
    }
    if (index == -1)
    {
        cout << "Нужная гитара не найдена" << endl;
        return getElectricGuitar(0);
    } else
    {
        return getElectricGuitar(index);
    }

}

