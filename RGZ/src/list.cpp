

#include "list.h"


List::List() {}

List::List(const List &copy) :index(copy.index), guitars(copy.guitars){}


List::~List(){
    while(!guitars.empty()){
        guitars.pop_back();
    }
    guitars.clear();
    guitars.shrink_to_fit();
}

void List::DeleteAll() {
    while (!guitars.empty()) {
        guitars.pop_back();
    }
    guitars.clear();
    guitars.shrink_to_fit();
    index = -1;
}

void List::addGuitar(Guitar *guitar) {
    index += 1;
    if (index >= 255){
        return;
    }
    this->guitars.push_back(guitar->clone());
}

vector<Guitar*> List::getGuitar() {
    return this->guitars;
}

void List::setGuitar(vector<Guitar *> &book1) {

    this->guitars = book1;
    index = book1.size();
}

void List::showAll() const {
    for (int i = 0; i < guitars.size(); ++i) {
        guitars[i]->print();
        cout << endl;
    }
}

void List::DeleteElement(int index) {
    if (index > guitars.size()){
        index = guitars.size();
    }else if (index < 0){
        index = 0;
    }
    vector<Guitar*>::iterator pos = guitars.begin() + index;
    guitars.erase(pos);
    this->index--;
}

