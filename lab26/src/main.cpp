#include "list.h"

int main()
{

    auto *strings = new Gitar_strings;

    List * list = new List;


    strings->setmin_string_thickness(8);
    strings->setmaterials(Synthetic);

    auto *guitar = new Guitar;
    guitar->setpickup(true);
    guitar->setfirm("Fender");
    guitar->setguitar_tunes(19);
    guitar->setstrings(strings);
    guitar->setguitar_size(size);

    Guitar guitar1(true, "Yamaha", 19, Gitar_strings(9, Stainless_steel),size  );
    Guitar guitar2(false, "Cort", 20, Gitar_strings(9, Bronze), size2);
    Guitar guitar3(true, "Jackson", 21, Gitar_strings(11, Copper), size4);


    list->addGuitar(*guitar);
    list->addGuitar(guitar1);
    list->addGuitar(guitar2);
    list->addGuitar(guitar3);

    // --------------------------------------haslednik 1

    AcousticGuitar acousticGuitar(true, "Yamaha", 22, Gitar_strings(9, Bronze ), size, 65, Seven);
    AcousticGuitar acousticGuitar2(true, "Yamaha", 19, Gitar_strings(11, Gold ), size2, 80, Six);
    AcousticGuitar acousticGuitar3(false, "Yamaha", 26, Gitar_strings(8, Copper ), size4, 10, Twelve);

    auto * listAcousticGuitar = new ListAcousticGuitar;

    listAcousticGuitar->addGuitar(acousticGuitar);
    listAcousticGuitar->addGuitar(acousticGuitar2);
    listAcousticGuitar->addGuitar(acousticGuitar3);

    cout << endl;
    listAcousticGuitar->ShowAll();
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    listAcousticGuitar->Colektion_Guitar();
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    //--------------------------------------------haslednik 2

    ElectricGuitar electricGuitar(false, "Yamaha", 26, Gitar_strings(8, Copper ), size4, 1, Super_start);
    ElectricGuitar electricGuitar2(false, "Fender", 27, Gitar_strings(9, Bronze ), size, 2, Les_paul);
    ElectricGuitar electricGuitar3(false, "Cort", 19, Gitar_strings(10, Stainless_steel ), size3, 3, Telecaster);

    auto * listElectricGuitar = new ListElectricGuitar;

    listElectricGuitar->addGuitar(electricGuitar);
    listElectricGuitar->addGuitar(electricGuitar2);
    listElectricGuitar->addGuitar(electricGuitar3);

    cout << endl;
    listElectricGuitar->ShowAll();
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    listElectricGuitar->Colektion_Guitar2();
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

}
