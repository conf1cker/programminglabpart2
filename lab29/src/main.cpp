#include "list.hpp"

int main()
{
    List<int> listint;

    int a = 1;
    int b = 2;
    int c = 0;

    listint.addElement(&a);
    listint.addElement(&b);
    listint.addElement(&c);

    int res = listint.getElement(1);
    cout << res << endl << endl;

    listint.SortList();

    int min = listint.FindMinElement();
    cout << min << endl << endl;
    listint.ShowList();
    cout << endl;

    List<char> listchar;

    char sym1 = 'k';
    char sym2 = 'i';
    char sym3 = 't';
    char sym4 = '1';
    char sym5 = '2';
    char sym6 = '0';
    char sym7 = 'a';

    listchar.addElement(&sym1);
    listchar.addElement(&sym2);
    listchar.addElement(&sym3);
    listchar.addElement(&sym4);
    listchar.addElement(&sym5);
    listchar.addElement(&sym6);
    listchar.addElement(&sym7);


    listchar.deleteElement(2);
    listchar.ShowList();
    cout << endl;
    listchar.SortList();
    listchar.ShowList();



    return 0;
}
