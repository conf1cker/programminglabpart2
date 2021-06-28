#include "../src/list.h"

bool test_tostring(){
    bool result = true;

    Guitar guitar1(true, "Yamaha", 19, Gitar_strings(9, Stainless_steel),size  );


    string expected = "1 Yamaha 19 9 1 1\n";
    string actual = guitar1.toString();

    if (actual == expected) {
        result &= true;
    }else{
        result &= false;
    }

    return  result;
}

bool test_convert_string_to_object(){
    bool result = true;
    string obj = "1 Tomson 23 8 Stainless_steel size";

    Guitar expected (true, "Tomson", 23, Gitar_strings(8, Stainless_steel), size );
    Guitar actual = actual.convert_string_to_object(obj);

    if (actual.getpickup() == expected.getpickup()
        && actual.getguitar_tunes() == expected.getguitar_tunes()
        && actual.getfirm() == expected.getfirm()
        && actual.getstrings().getmin_string_thickness() == expected.getstrings().getmin_string_thickness()
        && actual.getguitar_size() == expected.getguitar_size())
    {
        result &= true;
    } else {
        result &= false;
    }



    return  result;
}

int main()
{
    bool result = true;
    cout<<"\n";
    result &= test_tostring();
    cout<<"Тест преврашение  в строку\n";
    if(result)
    {
        cout<<"Тест успешен\n";
    }
    else
    {
        cout<<"Тест не успешен\n";
    }
    result &= test_convert_string_to_object();
    cout<<"Тест преврашение  в объект\n";
    if(result)
    {
        cout<<"Тест успешен\n";
    }
    else
    {
        cout<<"Тест не успешен\n";
    }

}


