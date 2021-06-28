
#include "../src/lib.h"

bool test_Sort_struct_by_criterion()
{
    bool result = true;

    struct Guitar ** guitar = malloc(3 * sizeof (struct Guitar));
    for(int i = 0; i < 3; i++)
    {
        *(guitar + i) = malloc(sizeof (struct Guitar));
    }

    (*(guitar+0))->pickup = 1;
    strcpy((*(guitar+0))->firm, "Fender");
    (*(guitar+0))->guitar_tunes = 21;
    (*(guitar+0))->strings.min_string_thickness = 11;
    (*(guitar+0))->strings.materials = Synthetic;
    (*(guitar+0))->guitar_tunes = size4;

    (*(guitar+1))->pickup = 0;
    strcpy((*(guitar+1))->firm, "Takamine");
    (*(guitar+1))->guitar_tunes = 23;
    (*(guitar+1))->strings.min_string_thickness = 9;
    (*(guitar+1))->strings.materials = Bronze;
    (*(guitar+1))->guitar_tunes = size;

    (*(guitar+2))->pickup = 1;
    strcpy((*(guitar+2))->firm, "Fender");
    (*(guitar+2))->guitar_tunes = 22;
    (*(guitar+2))->strings.min_string_thickness = 10;
    (*(guitar+2))->strings.materials = Gold;
    (*(guitar+2))->guitar_tunes = size2;

    Sort_struct_by_criterion(guitar, "tunes", 1);

    struct Guitar ** expectedLD = malloc(3 * sizeof (struct Guitar));
    for(int i = 0; i < 3; i++)
    {
        *(expectedLD + i) = malloc(sizeof (struct Guitar));
    }

    (*(expectedLD+0))->pickup = 1;
    strcpy((*(expectedLD+0))->firm, "Fender");
    (*(expectedLD+0))->guitar_tunes = 21;
    (*(expectedLD+0))->strings.min_string_thickness = 11;
    (*(expectedLD+0))->strings.materials = Synthetic;
    (*(expectedLD+0))->guitar_tunes = size4;

    (*(expectedLD+1))->pickup = 1;
    strcpy((*(expectedLD+1))->firm, "Fender");
    (*(expectedLD+1))->guitar_tunes = 22;
    (*(expectedLD+1))->strings.min_string_thickness = 10;
    (*(expectedLD+1))->strings.materials = Gold;
    (*(expectedLD+1))->guitar_tunes = size2;

    (*(expectedLD+2))->pickup = 1;
    strcpy((*(expectedLD+2))->firm, "Fender");
    (*(expectedLD+2))->guitar_tunes = 23;
    (*(expectedLD+2))->strings.min_string_thickness = 10;
    (*(expectedLD+2))->strings.materials = Gold;
    (*(expectedLD+2))->guitar_tunes = size2;


    for(int i = 0; i < 3; i++)
    {
        if ((*(guitar + i))->guitar_tunes == ((*(expectedLD + i))->guitar_tunes))
        {
            result &= true;
        }else{
            result &= false;
        }
    }
}




int main()
{
    bool test = true;
    test &= test_Sort_struct_by_criterion();
    if (test)
    {
        printf("All tests completed successfully\n");
    }else
    {
        printf("Some of the tests failed\n");
    }
    return 0;
}