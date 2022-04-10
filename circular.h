#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {  
    private:
        Node<T>* head;//sentinel
        int nodes; 
    public:
        CircularList() : head(new Node<T>()) {
            head->prev = head;
            head->next = head;
        }

        ~CircularList(){
            for (Node<T>* it = head->next; it->next != head; it = it->next){
                delete it;
            }
            delete head;
        }

        T front(){
            return head->next->data;
            //throw ("sin definir");
        }

        T back(){
            return head->prev->data;
            //throw ("sin definir");
        }

        void push_front(T data){
            auto nuevo = new Node<T>(data);
            nuevo->next = head->next;
            nuevo->prev = head;
            head->next->prev = nuevo;
            head->next = nuevo;
            //throw ("sin definir");
        }

        void push_back(T data){
            auto nuevo = new Node<T>(data);
            nuevo->next = head;
            nuevo->prev = head->prev;
            head->prev->next = nuevo;
            head->prev = nuevo;
            //throw ("sin definir");
        }

        T pop_front(){
            if(is_empty()){
                return head->data;
            }
            else{
                T val = head->next->data;
                head->next = head->next->next;
                delete head->next->prev;
                head->next->prev = head;
                return val;
            }
            //throw ("sin definir");
        }

        T pop_back(){
            if(is_empty()){
                return head->data;
            }
            else {
                T val = head->prev->data;
                head->prev = head->prev->prev;
                delete head->prev->next;
                head->prev->next = head;
                return val;
            }
            //throw ("sin definir");
        }

        T insert(T data, int pos){
            auto nuevo = new Node<T>(data);
            int size = this->size();
            if(is_empty() || pos == 0){
                nuevo->next = head->next;
                nuevo->prev = head;
                head->next->prev = nuevo;
                head->next = nuevo;
            }
            else if(pos == size){
                nuevo->next = head;
                nuevo->prev = head->prev;
                head->prev->next = nuevo;
                head->prev = nuevo;
            }
            else if(pos>0 && pos<size){
                Node<T>* temp = head->next;
                for(int i = 0; i < pos - 1; i++)
                    temp = temp->next;
                nuevo->next = temp->next;
                nuevo->prev = temp;
                temp->next->prev = nuevo;
                temp->next = nuevo;
            }
            else
                throw exception ("posicion no valida");
            return nuevo->data;
        }

        void remove(int pos){
            int size = this->size();
            if(is_empty()){
                return;
            }
            else if(pos == 0){
                head->next = head->next->next;
                delete head->next->prev;
                head->next->prev = head;
            }
            else if(pos == size){
                head->prev = head->prev->prev;
                delete head->prev->next;
                head->prev->next = head;
            }
            else if(pos>0 && pos<size){
                Node<T>* temp = head->next;
                for (int i = 0; i < pos; ++i){
                    temp = temp->next;
                }
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                delete temp;
            }
            else
                throw exception ("posicion no valida");
        }

        T& operator[](int pos){
            auto temp = head;
            int size = this->size();
            if(is_empty()){
                return head->data;
            }
            else if(pos == 0){
                return head->next->data;
            }
            else if(pos == size){
                return head->prev->data;
            }
            else if(pos>0 && pos<size){
                for (int i = 0; i < pos; ++i) {
                    temp = temp->next;
                }
                return temp->data;
            }
            else
                throw exception ("posicion no valida");
        }

        bool is_empty(){
            return head->prev == head;
            //throw ("sin definir");
        }

        int size(){
            int cont = 0;
            for (Node<T>* it = head->next; it != head; it = it->next){
                cont++;
            }
            return cont;
            //throw ("sin definir");
        }

        void clear(){
            if(is_empty()){
                return;
            }
            else{
                for(Node<T>* it = head->next; it != head; it = it->next){
                    delete it;
                }
            }
            head->prev = head;
            head->next = head;
            //throw ("sin definir");
        }

        void sort(){
            if (is_empty() || size()==1){
                return;
            }
            else{
                Node<T>* sorted;
                sorted->next=sorted;
                sorted->prev=sorted;
                Node<T>* temp1 = head->next;
                while (temp1 != head) {
                    temp1->prev = temp1->next = nullptr;
                    Node<T>* temp2;
                    if(sorted->next == sorted)
                        sorted->next = temp1;
                    else if(sorted->next->data >= temp1->data) {
                        temp1->next = sorted->next;
                        temp1->next->prev = temp1;
                        sorted->next = temp1;
                    }
                    else {
                        Node<T>* temp2 = sorted->next;
                        while (temp2->next != sorted && temp2->next->data < temp1->data)
                            temp2 = temp2->next;
                        temp1->next = temp2->next;
                        if (temp2->next != sorted)
                            temp1->next->prev = temp1;
                        temp2->next = temp1;
                        temp1->prev = temp2;
                    }
                    temp1 = temp1->next;
                }
                head = sorted;
            }
            //throw ("sin definir");
        }

        bool is_sorted(){
            int cont = 0;
            for (Node<T>* it = head->next; it->next != head; it = it->next){
                if(it < it->next)
                    cont++;
            }
            return cont == size()-1;
            //throw ("sin definir");
        }

        void reverse(){
            Node<T>* it = head->next;
            Node<T>* temp = nullptr;

            while (it != head) {
                temp = it->prev;
                it->prev = it->next;
                it->next = temp;
                it = it->prev;
            }
            if(temp != nullptr)
                head->next = temp->prev;
            //throw ("sin definir");
        }

        string name(){
            return "ForwardList";
        }

};

#endif