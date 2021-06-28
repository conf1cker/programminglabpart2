

#include "controller.h"

List* Controller::getlist() {
    return &list;
}


void Controller::ReadFromFile(const string &path) {

    ifstream in;
    in.open(path);
    string object;

    AcousticGuitar  acoustic;

    ElectricGuitar  electric;

    char type;
    int pickup;
    int guitar_tunes;
    string firm;
    int min_string_thickness;
    int materials;
    int guitar_size;

    int distance_between_decks;
    int quantity;

    int number_of_regulators;
    int coppus;





    if (in.is_open()) {
        while (!in.eof()) {
            in >> type;
            if (type == 'A') {
                in >> pickup;
                in >> firm;
                in >> guitar_tunes;
                in >> min_string_thickness;
                in >> materials;
                in >> guitar_size;
                in >> distance_between_decks;
                in >> quantity;



                acoustic.setpickup(pickup);
                acoustic.setfirm(firm);
                acoustic.setguitar_tunes(guitar_tunes);
                if (materials == 0) {
                    Gitar_strings gitar_strings(min_string_thickness, Synthetic);
                    acoustic.setstrings(&gitar_strings);
                }
                else if(materials == 1){
                    Gitar_strings gitar_strings1(min_string_thickness,Stainless_steel);
                    acoustic.setstrings(&gitar_strings1);
                }
                else if(materials == 2){
                    Gitar_strings gitar_strings2(min_string_thickness,Gold);
                    acoustic.setstrings(&gitar_strings2);
                }
                else if(materials == 3){
                    Gitar_strings gitar_strings3(min_string_thickness,Steel_and_nicole);
                    acoustic.setstrings(&gitar_strings3);
                }
                else if(materials == 4){
                    Gitar_strings gitar_strings4(min_string_thickness,Bronze);
                    acoustic.setstrings(&gitar_strings4);
                }
                else if(materials == 5){
                    Gitar_strings gitar_strings5(min_string_thickness,Copper);
                    acoustic.setstrings(&gitar_strings5);
                }

                if (guitar_size == 0) acoustic.setguitar_size(size);
                else if (guitar_size == 1) acoustic.setguitar_size(size2);
                else if (guitar_size == 2) acoustic.setguitar_size(size3);
                else if (guitar_size == 3) acoustic.setguitar_size(size4);

                acoustic.setdistance_between_decks(distance_between_decks);
                if (quantity == 0) acoustic.setquantity(Six);
                else if (quantity == 1) acoustic.setquantity(Seven);
                else if (quantity == 2) acoustic.setquantity(Twelve);


                list.addGuitar(&acoustic);


            } else if (type == 'E') {
                in >> pickup;
                in >> firm;
                in >> guitar_tunes;
                in >> min_string_thickness;
                in >> materials;
                in >> guitar_size;

                in >> number_of_regulators;
                in >> coppus;



                electric.setpickup(pickup);
                electric.setfirm(firm);
                electric.setguitar_tunes(guitar_tunes);
                if (materials == 0) {
                    Gitar_strings gitar_strings(min_string_thickness, Synthetic);
                    electric.setstrings(&gitar_strings);
                }
                else if(materials == 1){
                    Gitar_strings gitar_strings1(min_string_thickness,Stainless_steel);
                    electric.setstrings(&gitar_strings1);
                }
                else if(materials == 2){
                    Gitar_strings gitar_strings2(min_string_thickness,Gold);
                    electric.setstrings(&gitar_strings2);
                }
                else if(materials == 3){
                    Gitar_strings gitar_strings3(min_string_thickness,Steel_and_nicole);
                    electric.setstrings(&gitar_strings3);
                }
                else if(materials == 4){
                    Gitar_strings gitar_strings4(min_string_thickness,Bronze);
                    electric.setstrings(&gitar_strings4);
                }
                else if(materials == 5){
                    Gitar_strings gitar_strings5(min_string_thickness,Copper);
                    electric.setstrings(&gitar_strings5);
                }

                if (guitar_size == 0) electric.setguitar_size(size);
                else if (guitar_size == 1) electric.setguitar_size(size2);
                else if (guitar_size == 2) electric.setguitar_size(size3);
                else if (guitar_size == 3) electric.setguitar_size(size4);

                electric.setnumber_of_regulators(number_of_regulators);

                if (guitar_size == 0) electric.setcoppus(Stratocaster);
                else if (guitar_size == 1) electric.setcoppus(Super_start);
                else if (guitar_size == 2) electric.setcoppus(Telecaster);
                else if (guitar_size == 3) electric.setcoppus(Les_paul);

                list.addGuitar(&electric);


            }
        }
    }
    in.close();
}

void Controller::WriteToFile(const string &path) {

    ofstream out;
    out.open(path);

    auto temp = list.getGuitar();

    for(int i = 0; i < temp.size(); i++){
        if(out.is_open()){
            if(temp[i]->GetType() == 'A'){
                out << ((AcousticGuitar*)temp[i]->clone())->getpickup();
                out << "  ";
                out << ((AcousticGuitar*)temp[i]->clone())->getfirm();
                out << "  ";
                out << ((AcousticGuitar*)temp[i]->clone())->getguitar_tunes();
                out << "  ";
                out << ((AcousticGuitar*)temp[i]->clone())->getstrings().getmin_string_thickness();
                out << "  ";
                out << ((AcousticGuitar*)temp[i]->clone())->getstrings().getmaterials();
                out << "  ";
                out << ((AcousticGuitar*)temp[i]->clone())->getguitar_size();
                out << "  ";
                out << ((AcousticGuitar*)temp[i]->clone())->getdistance_between_decks();
                out << "  ";
                out << ((AcousticGuitar*)temp[i]->clone())->getquantity();
                out << endl;
            }else if(temp[i]->GetType() == 'E'){
                out << ((ElectricGuitar*)temp[i]->clone())->getpickup();
                out << "  ";
                out << ((ElectricGuitar*)temp[i]->clone())->getfirm();
                out << "  ";
                out << ((ElectricGuitar*)temp[i]->clone())->getguitar_tunes();
                out << "  ";
                out << ((ElectricGuitar*)temp[i]->clone())->getstrings().getmin_string_thickness();
                out << "  ";
                out << ((ElectricGuitar*)temp[i]->clone())->getstrings().getmaterials();
                out << "  ";
                out << ((ElectricGuitar*)temp[i]->clone())->getguitar_size();
                out << "  ";
                out << ((ElectricGuitar*)temp[i]->clone())->getnumber_of_regulators();
                out << "  ";
                out << ((ElectricGuitar*)temp[i]->clone())->getcoppus();
                out << endl;
            }
        }else break;
    }
}



bool predCol(Guitar *a){

    if (a->GetType() == 'A' || a->GetType() == 'E') {
        auto *Guitar = (AcousticGuitar *) a->clone();
        if (Guitar->getpickup() == 0 && Guitar->getstrings().getmin_string_thickness() >= 9) {
            delete Guitar;
            return true;
        } else {
            delete Guitar;
            return false;
        }
    }else{
        return false;
    }

}

vector<Guitar*>  Controller::the_first_method_for_working_with_collection()
{
    vector<Guitar*> temp;
    auto temp1 = list.getGuitar();
    auto iter = temp1.begin();
    while(*iter){
        iter = find_if(iter, temp1.end(), predCol);

        if(iter == temp1.end()) break;
        ((Guitar*)*iter)->print();
        cout<<endl;
        temp.push_back((Guitar*)*iter);
        iter++;
    }
    return temp;
}

bool predCol2(Guitar *a){

    if ( a->GetType() == 'E') {
        int pok = 0;
        auto *Guitar = (AcousticGuitar *) a->clone();
        if (Guitar->getfirm() == "Fender" && Guitar->getguitar_tunes() == 27 && pok == 0) {
            const int pok = 1;
            delete Guitar;
            return true;
        } else if (Guitar->getfirm() == "Fender" && Guitar->getguitar_tunes() == 26 && pok == 0) {
            const int pok = 1;
            delete Guitar;
            return true;
        } else if (Guitar->getfirm() == "Fender" && Guitar->getguitar_tunes() == 25 && pok == 0) {
            const int pok = 1;
            delete Guitar;
            return true;
        } else if (Guitar->getfirm() == "Fender" && Guitar->getguitar_tunes() == 24 && pok == 0) {
            const int pok = 1;
            delete Guitar;
            return true;
        } else if (Guitar->getfirm() == "Fender" && Guitar->getguitar_tunes() == 23 && pok == 0) {
            const int pok = 1;
            delete Guitar;
            return true;
        } else if (Guitar->getfirm() == "Fender" && Guitar->getguitar_tunes() == 22 && pok == 0) {
            const int pok = 1;
            delete Guitar;
            return true;
        } else if (Guitar->getfirm() == "Fender" && Guitar->getguitar_tunes() == 21 && pok == 0) {
            const int pok = 1;
            delete Guitar;
            return true;
        } else if (Guitar->getfirm() == "Fender" && Guitar->getguitar_tunes() == 20 && pok == 0) {
            const int pok = 1;
            delete Guitar;
            return true;
        } else if (Guitar->getfirm() == "Fender" && Guitar->getguitar_tunes() == 19 && pok == 0) {
            const int pok = 1;
            delete Guitar;
            return true;
        } else {
            delete Guitar;
            return false;
        }
    }else{
        return false;
    }

}

vector<Guitar*> Controller::the_second_method_for_working_with_collection()
{
    vector<Guitar*> temp;
    auto temp1 = list.getGuitar();
    auto iter = temp1.begin();
    while(*iter){
        iter = find_if(iter, temp1.end(), predCol2);
        if(iter == temp1.end()) break;
        ((Guitar*)*iter)->print();
        cout<<endl;
        temp.push_back((Guitar*)*iter);
        iter++;
    }
    return temp;

}

bool functorfirm(Guitar* A, Guitar* B){
    bool result = false;
    if (A->GetType() == 'A' && B->GetType() == 'A') {
        auto *temp1 = (AcousticGuitar *) A->clone();
        auto *temp2 = (AcousticGuitar *) B->clone();
        if (temp1->getfirm() > temp2->getfirm()) {
            result = true;
        }
        delete temp1;
        delete temp2;
    }
    if (A->GetType() == 'E' && B->GetType() == 'E') {
        auto *temp3 = (ElectricGuitar *) A->clone();
        auto *temp4 = (ElectricGuitar *) B->clone();
        if (temp3->getfirm() > temp4->getfirm()) {
            result = true;
        }
        delete temp3;
        delete temp4;
    }
    if (A->GetType() == 'A' && B->GetType() == 'E') {
        auto *temp3 = (AcousticGuitar *) A->clone();
        auto *temp1 = (ElectricGuitar *) B->clone();
        if (temp3->getfirm() > temp1->getfirm()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    if (A->GetType() == 'E' && B->GetType() == 'A') {
        auto *temp1 = (ElectricGuitar *) A->clone();
        auto *temp3 = (AcousticGuitar *) B->clone();
        if (temp1->getfirm() > temp3->getfirm()) {
            result = true;
        }
        delete temp1;
        delete temp3;
    }

    return result;
}

vector<Guitar*> Controller::the_third_method_for_working_with_collection()
{
    vector<Guitar*> temp;
    auto temp1 = list.getGuitar();

    temp.reserve(temp1.size());
    copy(temp1.begin(), temp1.end(), back_inserter(temp));
    sort(temp.begin(), temp.end(), functorfirm);
    auto iter = temp.begin();
    int contr =0;
    for (int i = 0; i < temp.size(); ++i) {
        temp[i]->print();
    }
    cout << "-----------"<<endl;
    for (int i = 0; i < temp.size(); ++i) {
        if(temp[i]->GetType() == 'A'){
            if(((AcousticGuitar*)temp[i]->clone())->getstrings().getmaterials() == 4 && contr == 0){
                contr++;
            }else if(((AcousticGuitar*)temp[i]->clone())->getstrings().getmaterials() == 4 && contr == 1){
                temp[i]->print();
            }

        }
        else if(temp[i]->GetType() == 'E'){
            if(((ElectricGuitar*)temp[i]->clone())->getstrings().getmaterials() == 4 && contr == 0){
                contr++;
            }else if(((ElectricGuitar*)temp[i]->clone())->getstrings().getmaterials() == 4 && contr == 1){
                temp[i]->print();
            }

        }
    }
    return temp;
}