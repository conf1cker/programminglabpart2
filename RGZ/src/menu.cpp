

#include "menu.h"

void  Menu ::User_menu() {

    controller.ReadFromFile("/home/programminglabpart2/RGZ/guitar_rgz.txt");
    for (int i =0; i < 100; ++i)
    {

        int index;
        cout << "Menu" << endl;
        cout << "1. Показать список ." << endl;
        cout << "2. Удалить список." << endl;
        cout << "3. Удалить по индексу." << endl;
        cout << "4. Получить элемент по индексу." << endl;
        cout << "5. Добавитьть элемент." << endl;
        cout << "6. 1 метод роботы с колекцией." << endl;
        cout << "7. 2 метод роботы с колекцией." << endl;
        cout << "8. 3 метод роботы с колекцией." << endl;
        cout << "9. Запись в файл." << endl;
        cout << "10. Выход." << endl;
        cin >> index;



        switch (index)
        {
            case 1:
            {
                cout << "Here your list: " << endl;
                controller.getlist()->showAll();
                cout << endl;
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "You deleted all elements: " << endl;
                controller.getlist()->DeleteAll();
                cout << "Your list now: empty" << endl;
                controller.getlist()->showAll();
                cout << endl;
                cout << endl;
                break;
            }
            case 3:
            {
                cout << "Enter the index of element you want to delete: " << endl;
                int pos;
                cin >> pos;
                controller.getlist()->DeleteElement(pos);
                cout << "Element successfully deleted." << endl;
                cout << endl;
                break;
            }
            case 4:
            {
                cout << "Enter the index of element you want to get: " << endl;
                int index;
                cin >> index;
                vector<Guitar *>::iterator iter = controller.getlist()->getGuitar().begin();
                iter += index;
                (*iter)->print();
                cout << endl;
                break;
            }
            case 5:
            {
                cout << "Adding element" << endl;
                cout << "Is this fiction book or science book: 0 - AcousticGuitar book, 1 - ElectricGuitar book " << endl;
                int checker;
                cin >> checker;
                if (checker == 0)
                {
                    AcousticGuitar acousticGuitar;
                    cin >> acousticGuitar;
                    acousticGuitar.print();

                    cout << "Do you want to add it in the end of the list or by index: 0 - end, 1 - by index: " << endl;
                    int checker_add;
                    cin >> checker_add;
                    if (checker_add == 0) {
                        cout << "Your list: " << endl;
                        controller.getlist()->addGuitar(&acousticGuitar);
                        controller.getlist()->showAll();
                    } else if (checker_add == 1) {
                        auto iter = controller.getlist()->getGuitar().begin();
                        int iter_pos;
                        cout << "Enter the index, after which you want to add your book: " << endl;
                        cin >> iter_pos;
                        auto temp = controller.getlist()->getGuitar();
                        temp.insert(iter + iter_pos, acousticGuitar.clone());
                        controller.getlist()->setGuitar(temp);
                        cout << "Your list: " << endl;
                        controller.getlist()->showAll();
                    }
                } else if (checker == 1)
                {
                    ElectricGuitar electricGuitar;
                    cin >> electricGuitar;
                    electricGuitar.print();
                    cout << "Do you want to add it in the end of the list or by index: 0 - end, 1 - by index: " << endl;
                    int checker_add;
                    cin >> checker_add;
                    if (checker_add == 0) {
                        cout << "Your list: " << endl;
                        controller.getlist()->addGuitar(&electricGuitar);
                        controller.getlist()->showAll();
                    } else if (checker_add == 1) {
                        auto iter = controller.getlist()->getGuitar().begin();
                        int iter_pos;
                        cout << "Enter the index, after which you want to add your book: " << endl;
                        cin >> iter_pos;
                        auto temp = controller.getlist()->getGuitar();
                        temp.insert(iter + iter_pos, electricGuitar.clone());
                        controller.getlist()->setGuitar(temp);
                        cout << "Your list: " << endl;
                        controller.getlist()->showAll();
                    }
                }
                break;
            }
            case 6:
            {
                cout << "the_first_method_for_working_with_collection: " << endl;
                controller.the_first_method_for_working_with_collection();
                cout << endl;
                break;
            }
            case 7:
            {
                cout << "the_second_method_for_working_with_collection: " << endl;
                controller.the_second_method_for_working_with_collection();
                cout << endl;
                break;
            }
            case 8:
            {
                cout << "the_thirt_method_for_working_with_collection: " << endl;
                controller.the_third_method_for_working_with_collection();
                cout << endl;
                break;
            }
            case 9:
            {
                controller.WriteToFile("/home/sascha/Programing/RGZ/guitar_rgz_result.txt");
                break;
            }
            case 10:
            {
                return;
            }
            default:
                printf("ERROR: Wrong option!\n");
                printf("\n\n");
                break;
        }
    }
}
