#include "list.h"
int main()
{

    List list;

    AcousticGuitar acousticGuitar(true, "Yamaha", 22, Gitar_strings(9, Bronze ), size, 65, Seven);
    AcousticGuitar acousticGuitar2(true, "Yamaha", 19, Gitar_strings(11, Gold ), size2, 80, Six);
    AcousticGuitar acousticGuitar3(false, "Yamaha", 26, Gitar_strings(8, Copper ), size4, 10, Twelve);



    list.addGuitar(acousticGuitar);
    list.addGuitar(acousticGuitar2);
    list.addGuitar(acousticGuitar3);


    ElectricGuitar electricGuitar(false, "Yamaha", 26, Gitar_strings(8, Copper ), size4, 1, Super_start);
    ElectricGuitar electricGuitar2(false, "Fender", 27, Gitar_strings(9, Bronze ), size, 2, Les_paul);
    ElectricGuitar electricGuitar3(false, "Cort", 19, Gitar_strings(10, Stainless_steel ), size3, 3, Telecaster);



    list.addGuitar(electricGuitar);
    list.addGuitar(electricGuitar2);
    list.addGuitar(electricGuitar3);


    list.ShowAll();
}



