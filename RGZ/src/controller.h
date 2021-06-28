

#ifndef RGZ_CONTROLLER_H
#define RGZ_CONTROLLER_H

#include <list.h>

class Controller {
private:
    List list;
public:
    /**
   * Конструктор по умолчанию
   */
    Controller() = default;

    /**
* Деструктор по умолчанию
*/
    ~Controller() = default;

    /**
    * Метод чтения из файла
    */
    void ReadFromFile(const string &path);

    /**
    * Метод записи в файл
    */
    void WriteToFile(const string &path);

    /**
     * Геттер
    * доступа к списку
    */
    List* getlist();

    /**
    * Метод 1 колекции
    */
    vector<Guitar*> the_first_method_for_working_with_collection();
    /**
    * Метод 2 колекции
    */
    vector<Guitar*> the_second_method_for_working_with_collection();
    /**
    * Метод 3 колекции
    */
    vector<Guitar*> the_third_method_for_working_with_collection();






};

#endif //RGZ_CONTROLLER_H
