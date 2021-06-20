#include "Header.h"
//конструктор(присвоюємо вказівнику на початок NULL і к-сті елементів - 0)
template <class T>
List<T>::List(){
    start = nullptr;
    elementscount=0;
}
//виведення заданої к-сті елементів, працює аналогічно як ф-ція виведення нижче
//тільки ми виводимо поки наш лічильник не дійде заданої к-сті елементів в циклі
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
//виведення списку
//маємо тимчасовий вказівник, яким проганаяємося по всьому списку і виводимо всі значення
//якщо к-сть елементів 0, то ми виходимо з ф-ції
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
//додавання елементу в список
template <class T>
void List<T>::Add(T value){
    list* newnode = new list;
    newnode->value = value;
    //якщо в нас нема елементів, новий елемент стає початком
    //к-сть елементів збільшується
    if(start==nullptr){
        newnode->prev = newnode->next = newnode;
        start = newnode;
        elementscount++;
        return;
    }
    //якщо нове значення менше або рівне початкового, робимо його новим початком
    if(newnode->value<=start->value){
        list* last = start->prev;
        newnode->next = start;
        newnode->prev = last;
        last->next = start->prev = newnode;
        start = newnode;
        elementscount++;
        return;
    }
    //якщо нове значенння більше від кінця списку, нове значення стає
    //кінцем списку
    list*last = start->prev;
    if(newnode->value>last->value){
        newnode->next = start;
        start->prev = newnode;
        newnode->prev  =last;
        last->next = newnode;
        elementscount++;
        return;
    }
    //в інших випадках порівнюємо нове значення з іншими, і вставляємо його ,де потрібно
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
    //всі операції проведені вище виконуються зміною вказівників між елементами, при додавання елементу
    //в різні частини ми по суті просто перекладаємо вказівники між попереднім і наступним значенням
}
//специфікація методу додавання для стрічок
//відмінність полягає у використанні ф-ції strcmp - вона перевіряє місце стрічок в
// таблиці ASCII (по суті перевіряє місце в алфавіті)
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
//ф-ція для діставання к-сті елементів
template <class T>
int List<T>::GetElementsCount(){
    return elementscount;
}
//видалення елементу по позиції
template <class T>
void List<T>::Pop(int pos){
    if(pos<0){
        cout<<"Position can`t be lower than 0"<<endl;
        return;
    }
    if(pos>elementscount){
        return;
    }
    //видалення тільки початку списку, якщо в ньому лише один елемент
    if(elementscount==1){
        delete start;
        start = nullptr;
        elementscount--;
        return;
    }
    //видалення початку списку
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
    //видалення кінця списку
    if(pos==elementscount){
        list* last = start->prev;
        list*prev = last->prev;
        prev->next = start;
        start->prev = prev;
        delete last;
        elementscount--;
        return;
    }
    //в циклі шукаємо елемент по позиції
    //потім видаляємо
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
    //знову ж таки виокнуємо перестановку вказівників, тільки тепер для видалення
}
//шаблони, що будуть використовуватися в програмі
template class List<int>;
template class List<char*>;
template class List<char>;
template class List<double>;
