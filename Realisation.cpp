#include "Header.h"
//�����������(���������� ��������� �� ������� NULL � �-�� �������� - 0)
template <class T>
List<T>::List(){
    start = nullptr;
    elementscount=0;
}
//��������� ������ �-�� ��������, ������ ��������� �� �-��� ��������� �����
//����� �� �������� ���� ��� �������� �� ���� ������ �-�� �������� � ����
template <class T>
void List<T>::ShowList(int amount){
    if(amount>elementscount){
        return;
    }
    if(amount<0){
        cout<<"Number of elements can`t be lower than 0"<<endl;
        return;
    }
    list*tmp = start;
    for(int i=0;i<amount;i++){
        cout<<tmp->value<<endl;
        tmp = tmp->next;
    }
}
//��������� ������
//���� ���������� ��������, ���� ������������� �� ������ ������ � �������� �� ��������
//���� �-��� �������� 0, �� �� �������� � �-���
template <class T>
void List<T>::ShowList(){
    if(elementscount==0){
        return;
    }
    if(elementscount==1){
        cout<<start->value<<endl;
        return;
    }
    list*tmp = start;
    int i=0;
    while(i<elementscount){
        i++;
        cout<<tmp->value<<endl;
        tmp = tmp->next;
    }
}
//��������� �������� � ������
template <class T>
void List<T>::Add(T value){
    list* newnode = new list;
    newnode->value = value;
    //���� � ��� ���� ��������, ����� ������� ��� ��������
    //�-��� �������� ����������
    if(start==nullptr){
        newnode->prev = newnode->next = newnode;
        start = newnode;
        elementscount++;
        return;
    }
    //���� ���� �������� ����� ��� ���� �����������, ������ ���� ����� ��������
    if(newnode->value<=start->value){
        list* last = start->prev;
        newnode->next = start;
        newnode->prev = last;
        last->next = start->prev = newnode;
        start = newnode;
        elementscount++;
        return;
    }
    //���� ���� ��������� ����� �� ���� ������, ���� �������� ���
    //����� ������
    list*last = start->prev;
    if(newnode->value>last->value){
        newnode->next = start;
        start->prev = newnode;
        newnode->prev  =last;
        last->next = newnode;
        elementscount++;
        return;
    }
    //� ����� �������� ��������� ���� �������� � ������, � ���������� ���� ,�� �������
    list*tmp = start;
    while(tmp->value<=newnode->value){
        tmp = tmp->next;
    }
    list*prev = tmp->prev;
    newnode->next = tmp;
    tmp->prev = newnode;
    prev->next = newnode;
    newnode->prev = prev;
    elementscount++;
    //�� �������� �������� ���� ����������� ����� ��������� �� ����������, ��� ��������� ��������
    //� ��� ������� �� �� ��� ������ ����������� ��������� �� ��������� � ��������� ���������
}
//������������ ������ ��������� ��� ������
//�������� ������ � ����������� �-��� strcmp - ���� �������� ���� ������ �
// ������� ASCII (�� ��� �������� ���� � ������)
template<>
void List<char*>::Add(char *value){
    list* newnode = new list;
    newnode->value = value;
    if(start==nullptr){
        newnode->prev = newnode->next = newnode;
        start = newnode;
        elementscount++;
        return;
    }
    if(strcmp(start->value,newnode->value)>0||strcmp(start->value,newnode->value)==0){
        list* last = start->prev;
        newnode->next = start;
        newnode->prev = last;
        last->next = start->prev = newnode;
        start = newnode;
        elementscount++;
        return;
    }
    list*last = start->prev;
    if(strcmp(newnode->value,last->value)>0){
        newnode->next = start;
        start->prev = newnode;
        newnode->prev  =last;
        last->next = newnode;
        elementscount++;
        return;
    }
    list*tmp = start;
    while(strcmp(tmp->value,newnode->value)<=0){
        tmp = tmp->next;
    }
    list*prev = tmp->prev;
    newnode->next = tmp;
    tmp->prev = newnode;
    prev->next = newnode;
    newnode->prev = prev;
    elementscount++;
}
//�-��� ��� ��������� �-�� ��������
template <class T>
int List<T>::GetElementsCount(){
    return elementscount;
}
//��������� �������� �� �������
template <class T>
void List<T>::Pop(int pos){
    if(pos<0){
        cout<<"Position can`t be lower than 0"<<endl;
        return;
    }
    if(pos>elementscount){
        return;
    }
    //��������� ����� ������� ������, ���� � ����� ���� ���� �������
    if(elementscount==1){
        delete start;
        start = nullptr;
        elementscount--;
        return;
    }
    //��������� ������� ������
    if(pos==0){
        list* last = start->prev;
        list*next = start->next;
        next->prev=  last;
        last->next = next;
        delete start;
        start = next;
        elementscount--;
        return;
    }
    //��������� ���� ������
    if(pos==elementscount){
        list* last = start->prev;
        list*prev = last->prev;
        prev->next = start;
        start->prev = prev;
        delete last;
        elementscount--;
        return;
    }
    //� ���� ������ ������� �� �������
    //���� ���������
    int i=0;
    list* tmp = start;
    while(i!=pos){
        tmp = tmp->next;
        i++;
    }
    list*prev = tmp->prev;
    prev->next = tmp->next;
    tmp->next->prev = prev;
    delete tmp;
    elementscount--;
    //����� � ���� �������� ������������ ���������, ����� ����� ��� ���������
}
//�������, �� ������ ����������������� � �������
template class List<int>;
template class List<char*>;
template class List<char>;
template class List<double>;
