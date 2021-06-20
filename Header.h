#include <iostream>
#include <string.h>
using namespace std;
//шаблонний клас кільцевого двозв'язного списку
template <class T>
class List{
private:
    //структура однієї ланки списку(має вказівник на наступний і попередній елемент
    typedef struct LIST{
        T value;
        struct LIST* prev, *next;
    }list;
    //вказівник на початок списку
    list *start;
    //к-сть елементів у списку
    int elementscount;
public:
    List();
    void Add(T value);
    void Pop(int pos);
    int GetElementsCount();
    void ShowList();
    void ShowList(int amount);
};
