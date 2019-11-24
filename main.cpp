#include <iostream>
#include <new>
using namespace std;
class List{
    private:
        struct ListItem{
            int data;
            ListItem *next;
            ListItem *prev;
        
            ListItem(const int& data, ListItem* next=NULL, ListItem* prev=NULL){
                this->data = data;
                this->next = next;
                this->prev = prev;
            }
        };
    public://конструктор, деструктор
        List(){
            first = NULL;
            last = NULL;
        }
        ~List(){
            if( !isEmpty() ) removeAll();
        }
        bool isEmpty(){
            return first == NULL;
        }
        //
        //Методы на удаление
        //
        void removeAll(){
            while( first!=NULL ){
                ListItem *delItem;
                delItem = first;
                first = delItem->next;
                delete delItem;
            }
        }
        void removeAfterVal(int val){
            ListItem *delItem;
            ListItem *temp;
            ListItem *current = first->next;
            while( current != NULL){
                if(current->prev->data == val){
                    if(current->next != NULL){
                        temp = current->next;
                        temp->prev = current->prev;
                        current->prev->next = temp;
                    } else{
                        current->prev->next = NULL;
                        last = current->prev;
                    }
                    delItem = current;
                    delete delItem;
                    return;
                }
                current = current->next;
            }
            cout<<"The specified item does not exist.";
            return;
        }
        void removeBeforeVal(int val){
            ListItem *delItem;
            ListItem *temp;
            ListItem *current = first;
            while( current->next != NULL){
                if(current->next->data == val){
                    if(current->prev != NULL){
                        temp = current->prev;
                        temp->next = current->next;
                        current->next->prev = temp; 
                    } else {
                        first = current->next;
                        first->prev = NULL;
                   }
                    delItem = current;
                    delete delItem;
                    return;
                }
                current = current->next;
            }
            cout<<"The specified item does not exist.";
            return;
        }
        void removeAfterInd(int ind){
            ListItem *delItem;
            ListItem *temp;
            ListItem *current = first;
            int counter = 0;
            while( current->next !=NULL ){
                if(counter == ind){
                    delItem=current->next;
                    if(delItem->next != NULL){
                        temp = delItem->next;
                        temp->prev = current;
                        current->next = temp;
                    } else {
                        current->next = NULL;
                        last = current;
                    }
                    delete delItem;
                    return;
                }
                current = current->next;
                counter++;
            }
            cout<<"The specified item does not exist.";
            return;
        }
        void removeBeforeInd(int ind){
            ListItem *delItem;
            ListItem *temp;
            ListItem *current = first->next;
            int counter = 1;
            while( current !=NULL ){
                if(counter == ind){
                    delItem=current->prev;
                    if(delItem->prev != NULL){
                        temp = delItem->prev;
                        temp->next = current;
                        current->prev = temp;
                    } else {
                        current->prev = NULL;
                        first = current;
                    }
                    delete delItem;
                    return;
                }
                current = current->next;
                counter++;
            }
            cout<<"The specified item does not exist.";
            return;
        }
        // Методы печати
        void print(){
            ListItem *current = first;
            cout<<"Current list:"<<endl;    
            while( current->next != last->next ){
                cout << current->data << " ";
                current = current->next;
            }
            cout << current->data << endl;  
            cout << "Last is:" << last->data << endl;
        }
        void printReverse(){
            ListItem *current = last;
            cout<<"Current reversed list:"<<endl;
            while(current->prev != NULL ){
                cout << current->data << " ";
                current = current->prev;
            }
            cout << current->data << endl;
        }
        // 
        //Методы на добавление элемента
        // 
        void pushEnd(int data){
            ListItem *item = new ListItem( data );
            if( first == NULL ){
                first = item;
                last = item;
                return;
            }
            ListItem *current = first;
            while( current->next != NULL){
                current = current->next;
            }
            current->next = item;
            item->prev = current;
            last = item;
            return;
        }
        void pushAfterVal(int data, int val){
            ListItem *item = new ListItem( data );
            ListItem *temp;
            ListItem *current = first;
            while( current != NULL){
                if(current->data == val){
                    if(current->next != NULL){
                        temp = current->next;
                        temp->prev = item;
                        item->next = temp;
                    } else {
                        last = item;
                    }
                    item->prev = current;
                    current->next = item;
                    return;
                }
                current = current->next;
            }
            cout<<"The specified item does not exist.";
            return;
        }
        void pushBeforeVal(int data, int val){
            ListItem *item = new ListItem( data );
            ListItem *temp;
            ListItem *current = first;
            while( current != NULL){
                if(current->data == val){
                    if(current->prev == NULL){
                        first = item;
                        item->next = current;
                        current->prev = item;
                        return;
                    }
                    temp = current->prev;
                    temp->next = item;
                    item->prev = temp;
                    item->next = current;
                    current->prev = item;
                    return;
                }
                current = current->next;
            }
            cout<<"The specified item does not exist.";
            return;
        }
        void pushAfterInd(int data, int ind){
            int counter = 0;
            ListItem *item = new ListItem( data );
            ListItem *temp;
            ListItem *current = first;
            while( current != NULL){
                if(counter == ind){
                    if(current->next != NULL){
                        temp = current->next;
                        temp->prev = item;
                        item->next = temp;
                    } else {
                        last = item;
                    }
                    item->prev = current;
                    current->next = item;
                    return;
                }
                current = current->next;
                counter++;
            }
            cout<<"The specified item does not exist.";
            return;
        }
        void pushBeforeInd(int data, int ind){
            int counter = 0;
            ListItem *item = new ListItem( data );
            ListItem *temp;
            ListItem *current = first;
            while( current != NULL){
                if(counter == ind){
                    if(current->prev == NULL){
                        first = item;
                        item->next = current;
                        current->prev = item;
                        return;
                    }
                    temp = current->prev;
                    temp->next = item;
                    item->prev = temp;
                    item->next = current;
                    current->prev = item;
                    return;
                }
                current = current->next;
                counter++;
            }
            cout<<"The specified item does not exist.";
            return;
        }
        // 
        //Методы на поиск
        // 
        int findBeforeVal(int val){
            ListItem *current = first;
            while(current->next != NULL){
                if(current->next->data == val){
                    return current->data;
                }
                current = current->next;
            }
            cout<<"The specified item does not exist. Returned:";
            return -1;
        }
        int findAfterVal(int val){
            ListItem *current = first->next;
            while(current != NULL){
                if(current->prev->data == val){
                    return current->data;
                }
                current = current->next;
            }
            cout<<"The specified item does not exist. Returned:";
            return -1;
        }
        int findBeforeInd(int ind){
            ListItem *current = first->next;
            int counter = 1;
            while(current != NULL){
                if(counter == ind){
                    return current->prev->data;
                }
                current = current->next;
                counter++;
            }
            cout<<"The specified item does not exist. Returned:";
            return -1;
        }
        int findAfterInd(int ind){
            ListItem *current = first;
            int counter = 0;
            while(current->next != NULL){
                if(counter == ind){
                    return current->next->data;
                }
                current = current->next;
                counter++;
            }
            cout<<"The specified item does not exist. Returned:";
            return -1;
        }
        //
        //Сортировка, перестановка соседних элементов
        //
        void sort(){
            ListItem *current = first;
            while(current->next != NULL){
                if(current->data > current->next->data){
                    int temp = current->next->data;
                    current->next->data = current->data;
                    current->data = temp;
                    current = current->next;
                    sort();
                }
                else {
                    current = current->next;
                }
            }
        }
        void swap(int val){
            ListItem *current = first;
            while(current->next != NULL){
                if(current->data == val){
                    int temp = current->next->data;
                    current->next->data = current->data;
                    current->data = temp;
                    return;
                }
                current = current->next;
            }
            cout<<"The specified item does not exist.";
            return;
        }
        //
        //Организация кольцевого списка
        //
        void loop(){
            first->prev = last;
            last->next = first;
        }
        void unloop(){
            first->prev = NULL;
            last->next = NULL;
        }
        bool isLooped(){
            if (first->prev==NULL && last->next==NULL) return false;
            return true;
        }
    private:
        ListItem *first;
        ListItem *last;
};
int listRun(List& list){
    int actionInd, elemTemp, elemData;
    cout << "Choose list action:\n 1)Добавление элемента \n 2)Поиск элемента \n 3)Удаление элемента \n 4)Просмотр списка \n 5)Сортировка списка \n 6)Перестановка соседних элементов \n 7)Выход" << endl;
    cin >> actionInd;
    switch (actionInd)
    {
    case 1:
        cout << "Choose list action:\n 1)добавление элемента в список по значению после указанного элемента \n 2)добавление элемента в список по индексу после указанного элемента \n 3)добавление элемента в список перед указанным элементом по значению \n 4)добавление элемента в список  перед указанным элементом по индексу \n 5)Добавление элемента в конец" << endl;
        cin >> actionInd;
        switch (actionInd)
        {
        case 1:
            cout<<"Введите добавляемый элемент и значение указываемого элемента: \n";
            cin>>elemData>>elemTemp;
            list.pushAfterVal(elemData, elemTemp);
            break;
        
        case 2:
            cout<<"Введите добавляемый элемент и индекс указываемого элемента: \n";
            cin>>elemData>>elemTemp;
            list.pushAfterInd(elemData, elemTemp);
            break;
           
        case 3:
            cout<<"Введите добавляемый элемент и значение указываемого элемента: \n";
            cin>>elemData>>elemTemp;
            list.pushBeforeVal(elemData, elemTemp);
            break;
           
        case 4:
            cout<<"Введите добавляемый элемент и индекс указываемого элемента: \n";
            cin>>elemData>>elemTemp;
            list.pushBeforeInd(elemData, elemTemp);
            break;
            
        case 5:
            cout<<"Введите добавляемый элемент: \n";
            cin>>elemData;
            list.pushEnd(elemData);
            break;  
        default:
            cout<<"Недопустимое действие";
            return -1;
        }
        break;
    case 2:
        cout << "Choose list action:\n 1)поиск элемента списка по значению после указанного элемента \n 2)поиск элемента в списке по индексу после указанного элемента \n 3)поиск элемента в списке перед указанным элементом по значению \n 4)поиск элемента в списке перед указанным элементом по индексу" << endl;
        cin >> actionInd;
        switch (actionInd)
        {
        case 1:
            cout<<"Введите значение указываемого элемента: \n";
            cin>>elemTemp;
            cout<<list.findAfterVal(elemTemp);
            break;
        
        case 2:
            cout<<"Введите индекс указываемого элемента: \n";
            cin>>elemTemp;
            cout<<list.findAfterInd(elemTemp);
            break;
            
        case 3:
            cout<<"Введите значение указываемого элемента: \n";
            cin>>elemTemp;
            cout<<list.findBeforeVal(elemTemp);
            break;
           
        case 4:
            cout<<"Введите индекс указываемого элемента: \n";
            cin>>elemTemp;
            cout<<list.findBeforeInd(elemTemp);
            break;
            
        default:
            cout<<"Недопустимое действие";
            return -1;
        }
        break;
    case 3:
        cout << "Choose list action:\n 1)удаление элемента из списка по значению после указанного элемента \n 2)удаление элемента из списка по индексу после указанного элемента \n 3)удаление элемента из списка перед указанным элементом по значению \n 4)удаление элемента из списка перед указанным элементом по индексу \n" << endl;
        cin >> actionInd;
        switch (actionInd)
        {
        case 1:
            cout<<"Введите значение указываемого элемента: \n";
            cin>>elemTemp;
            list.removeAfterVal(elemTemp);
            break;
        
        case 2:
            cout<<"Введите индекс указываемого элемента: \n";
            cin>>elemTemp;
            list.removeAfterInd(elemTemp);
            break;
            
        case 3:
            cout<<"Введите значение указываемого элемента: \n";
            cin>>elemTemp;
            list.removeBeforeVal(elemTemp);
            break;
           
        case 4:
            cout<<"Введите индекс указываемого элемента: \n";
            cin>>elemTemp;
            list.removeBeforeInd(elemTemp);
            break;
            
        default:
            cout<<"Недопустимое действие";
            return -1;
        }
        break;
    case 4:
        cout << "Choose list action:\n 1)Просмотр списка слева направо \n 2)Просмотр списка справа налево" << endl;
        cin >> actionInd;
        switch (actionInd)
        {
        case 1:
            list.print();
            break;

        case 2:
            list.printReverse();
            break;

        default:      
            cout<<"Недопустимое действие";
            return -1;
        }
        break;
    
    case 5:
        cout<<"Отсортированный список:"<<endl;
        list.sort();
        break;

    case 6:
        cout<<"Введите значение элемента, он будет переставлен местами со следующим:"<<endl;
        cin>>elemTemp;
        list.swap(elemTemp);
        break;

    case 7:
        return -1;

    default:
        cout<<"Недопустимое действие"<< endl;
        break;
    }
    return 1;
}
int main(){
    List list;
    list.pushEnd(1);
    list.pushEnd(2);
    list.pushEnd(3);
    list.pushEnd(4);
    list.pushEnd(5);
    list.pushEnd(6);
    list.pushEnd(7);
    list.pushEnd(8);
    list.pushEnd(9);
    for(;;){
    if (listRun(list)==-1){
        break;
    };
    }
    return 0;
}