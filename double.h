#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
    public:
        DoubleList() : List<T>() {}

        ~DoubleList(){
            for (auto it = head; it->next != nullptr; it = it->next){
                delete it;
            }
            delete head;
            delete tail;
        }

        T front(){
            return head->data;
            //throw ("sin definir");
        }

        T back(){
            return tail->data;
            //throw ("sin definir");
        }

        void push_front(T data){
            auto nuevo = new Node<T>(data);
            if(is_empty()){
                head = nuevo;
                tail = nuevo;
            }
            else {
                nuevo->next = head;
                head->prev = nuevo;
                head = nuevo;
                //throw ("sin definir");
            }
        }

        void push_back(T data){
            auto nuevo = new Node<T>(data);
            if(is_empty()){
                head = nuevo;
                tail = nuevo;
            }
            else{
                nuevo->next = nullptr;
                nuevo->prev = tail;
                tail->next = nuevo;
                tail = nuevo;
            }
            //throw ("sin definir");
        }

        T pop_front(){
            if(is_empty()){
                return head->data;
            }
            else{
                T val = head->data;
                head = head->next;
                delete head->prev;
                head -> prev = nullptr;
                return val;
            }
            //throw ("sin definir");
        }

        T pop_back(){
            if(is_empty()){
                return head->data;
            }
            else {
                T val = tail->data;
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
                return val;
            }
            //throw ("sin definir");
        }

        T insert(T data, int pos){
            auto nuevo = new Node<T>(data);
            int size = this->size();
            if(is_empty()){
                head = nuevo;
                tail = nuevo;
            }
            else if(pos == 0){
                nuevo->next = head;
                head->prev = nuevo;
                head = nuevo;
            }
            else if(pos == size){
                nuevo->next = nullptr;
                nuevo->prev = tail;
                tail->next = nuevo;
                tail = nuevo;
            }
            else if(pos>0 && pos<size){
                auto temp = head;
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
                head = head -> next;
                delete head->prev;
                head -> prev = nullptr;
            }
            else if(pos == size){
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            }
            else if(pos>0 && pos<size){
                auto temp = head;
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
                return head->data;
            }
            else if(pos == size){
                return tail->data;
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
            return head == tail == reinterpret_cast<int>(nullptr);
            //throw ("sin definir");
        }

        int size(){
            int cont = 0;
            for (auto it = head; it != nullptr; it = it->next){
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
                for(auto it = head; it != nullptr; it = it->next){
                    delete it;
                }
            }
            head = tail = nullptr;
            //throw ("sin definir");
        }

        void sort(){
            if (is_empty() || size()==1){
                return;
            }
            else{
                Node<T>* sorted = nullptr;
                auto temp1 = head;
                while (temp1 != nullptr) {
                    temp1->prev = temp1->next = nullptr;
                    Node<T>* temp2;
                    if(sorted == nullptr)
                        sorted = temp1;
                    else if(sorted->data >= temp1->data) {
                        temp1->next = sorted;
                        temp1->next->prev = temp1;
                        sorted = temp1;
                    }
                    else {
                        Node<T>* temp2 = sorted;
                        while (temp2->next != nullptr && temp2->next->data < temp1->data)
                            temp2 = temp2->next;
                        temp1->next = temp2->next;
                        if (temp2->next != nullptr)
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
            for (auto it = head; it->next != nullptr; it = it->next){
                if(it < it->next)
                    cont++;
            }
            return cont == size()-1;
            //throw ("sin definir");
        }

        void reverse(){
            auto it = head;
            Node<T>* temp = nullptr;

            while (it != nullptr) {
                temp = it->prev;
                it->prev = it->next;
                it->next = temp;
                it = it->prev;
            }
            if(temp != nullptr)
                head = temp->prev;
            //throw ("sin definir");
        }

        string name(){
            return "ForwardList";
        }

};
#endif