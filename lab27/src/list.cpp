#include "list.h"

List::List() {}

List::List(const List &copy) :index(copy.index) {
    for (int i = 0; i <= copy.index; i++) {
        guitar[i] = copy.guitar[i]->clone();
    }
}

List::~List(){
    while (index >= 0){
        delete guitar[index];
        index--;
    }
}

void List::addGuirar(Guitar *guitar) {
    index += 1;
    if (index >= 255) {
        return;
    }
    guitar[index] = guitar->clone();
    cout << index;
}


Guitar* List::getGuirar(int index) const{
    if(index < 0){
        index= 0;
    }
    if(index >= this->index) {
        index = this->index - 1;
    }

    return guitar[index]->clone();
}

void List::ShowAll() const {
    for (int i = 0; i <= this->index; ++i) {
        guitar[i]->print();
        cout << endl;
    }
}


List& List::operator=(const List &copy) {
    if (this == &copy)
        return *this;
    while (index >= 0){
        delete guitar[index];
        index--;
    }
    for (int i = 0; i <= copy.index; i++) {
        guitar[i] = copy.guitar[i]->clone();
    }
    index = copy.index;
    return *this;
}
