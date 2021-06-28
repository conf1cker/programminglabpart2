
#ifndef RGZ_MENU_H
#define RGZ_MENU_H


#include "controller.h"

/**
 * Клас-меню
 */
class Menu {
private:
    Controller controller;
public:

    /**
   * Конструктор по умолчанию
   */
    Menu() = default;


    /**
   * Деструктор по умолчанию
   */
    ~Menu() = default;


    /**
    * Метод который использует меню
    *
    * Выводит на экран варианты действий
    */
    void User_menu();
};


#endif //RGZ_MENU_H
