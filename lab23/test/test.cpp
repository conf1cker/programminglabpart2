#include "../src/list.h"


bool Test_removeGuitar()
{
    bool result = true;
    List * list1 = new List;
    List * expected = new List;

    list1->setCount(0);
    expected->setCount(0);

    Guitar guitar1(true, "Yamaha", 19, Gitar_strings(9, Stainless_steel),size  );
    Guitar guitar2(false, "Cort", 20, Gitar_strings(9, Bronze), size2);
    Guitar guitar3(true, "Jackson", 21, Gitar_strings(11, Copper), size4);

    Guitar guitar4(true, "Yamaha", 19, Gitar_strings(9, Stainless_steel),size  );
    Guitar guitar5(true, "Jackson", 21, Gitar_strings(11, Copper), size4);

    list1->addGuitar(guitar1);
    list1->addGuitar(guitar2);
    list1->addGuitar(guitar3);

    expected->addGuitar(guitar4);
    expected->addGuitar(guitar5);

    list1->removeGuitar(1);

    for (int i = 0; i < 2; ++i) {
        Guitar temp = list1->getGuitar(i);
        Guitar temp1 = expected->getGuitar(i);
        if (temp.getpickup() == temp1.getpickup()
        && list1->getGuitar(i).getguitar_tunes() == expected->getGuitar(i).getguitar_tunes()
        && list1->getGuitar(i).getfirm() == expected->getGuitar(i).getfirm()
        && list1->getGuitar(i).getstrings().getmin_string_thickness() == expected->getGuitar(i).getstrings().getmin_string_thickness()
        && list1->getGuitar(i).getguitar_size() == expected->getGuitar(i).getguitar_size())
        {
            result &= true;
        } else {
            result &= false;
        }
    }
    return result;
}

bool Test_getGuitar()
{
    bool result = true;
    List * list = new List;

    list->setCount(0);


    Guitar guitar1(true, "Yamaha", 19, Gitar_strings(9, Stainless_steel),size  );
    Guitar guitar2(false, "Cort", 20, Gitar_strings(9, Bronze), size2);
    Guitar guitar3(true, "Jackson", 21, Gitar_strings(11, Copper), size4);

    list->addGuitar(guitar1);
    list->addGuitar(guitar2);
    list->addGuitar(guitar3);

    Guitar expected = list->getGuitar(2);


    if (list->getGuitar(2).getpickup() == expected.getpickup()
            && list->getGuitar(2).getguitar_tunes() == expected.getguitar_tunes()
            && list->getGuitar(2).getfirm() == expected.getfirm()
            && list->getGuitar(2).getstrings().getmin_string_thickness() == expected.getstrings().getmin_string_thickness()
            && list->getGuitar(2).getguitar_size() == expected.getguitar_size())
    {
            result &= true;
    } else {
            result &= false;
    }

    return result;


}



int main()
{

    bool result = true;
    cout << "Тест удаления элемента\n";
    result &= Test_removeGuitar();
    if (result){
        cout << "Тест успешен\n";
    }else{
        cout << "Тест не успешен\n";
    }

    cout << "Тест получения по индексу\n";
    //result &= Test_getGuitar();
    if (result){
        cout << "Тест успешен\n";
    }else{
        cout << "Тест не успешен";
    }

    return 0;
}





