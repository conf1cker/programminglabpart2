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
    //string result = obj_str ;

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
}

//----------------------------lab 25------------------------

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

ofstream & operator<<(ofstream &out ,const List& list){
    for (int i = 0; i < list.getcount(); ++i) {
        out << list[i];
    }
    return out;
}
