#include "../src/list.h"


bool Test_comparison_operator()
{
    bool result = true;

    Guitar guitar (true, "Yamaha", 19, Gitar_strings(9, Stainless_steel),size );
    Guitar guitar2 = guitar;

    if (guitar == guitar2) {
        result &= true;
    }else{
        result &= false;
    }

    return result;
}


bool Test_operator_equals()
{
    bool result = true;

    Guitar guitar (true, "Yamaha", 19, Gitar_strings(9, Stainless_steel),size );
    Guitar guitar2 (true, "Yamaha", 19, Gitar_strings(9, Stainless_steel),size );

    if (guitar == guitar2) {
        result &= true;
    }else{
        result &= false;
    }

    return result;

}

int main()
{
    bool result = true;
    cout << "Тест перегрузки оператора =\n";
    result &= Test_comparison_operator();
    if (result){
        cout << "Тест успешен\n";
    }else{
        cout << "Тест не успешен\n";
    }

    cout << "Тест перегрузки оператора ==\n";
    result &= Test_operator_equals();
    if (result){
        cout << "Тест успешен\n";
    }else{
        cout << "Тест не успешен";
    }


}