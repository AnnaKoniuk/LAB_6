#include <iostream>
#include <string.h>
using namespace std;
//��������� ���� ��������� �����'������ ������
template <class T>
class List{
private:
    //��������� ���� ����� ������(�� �������� �� ��������� � ��������� �������
    typedef struct LIST{
        T value;
        struct LIST* prev, *next;
    }list;
    //�������� �� ������� ������
    list *start;
    //�-��� �������� � ������
    int elementscount;
public:
    List();
    void Add(T value);
    void Pop(int pos);
    int GetElementsCount();
    void ShowList();
    void ShowList(int amount);
};
