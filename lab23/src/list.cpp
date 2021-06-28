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
        cout << "Подходящяя гитара не найдена" << endl;
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
