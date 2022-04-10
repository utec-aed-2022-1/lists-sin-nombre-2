#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include <string>
#include "list.h"

using namespace std;
// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes;

    public:
        ForwardList() : List<T>() {}

        ~ForwardList(){
            for (auto it = head; it->next != nullptr; it = it->next){
                delete it;
            }
            delete head;
        }

        T front(){
            return head->data;
            //throw ("sin definir");
        }

        T back(){
            auto it = head;
            while (it->next != nullptr)
                it = it->next;
            return it->data;
            //throw ("sin definir");
        }

        void push_front(T data){
            auto nuevo = new Node<T>;
            nuevo->data = data;
            nuevo->next = head;
            head = nuevo;
            //throw ("sin definir");
        }

        void push_back(T data){
            auto nuevo = new Node<T>;
            nuevo->data = data;
            if(head == nullptr){
                nuevo->next = head;
                head = nuevo;
            }
            else{
                auto it = head;
                while (it->next != nullptr)
                    it = it->next;
                it->next = nuevo;
                nuevo->next = nullptr;
            }
            //throw ("sin definir");
        }

        T pop_front(){
            T val = head->data;
            auto temp = head;
            head = head->next;
            delete temp;
            return val;
            //throw ("sin definir");
        }

        T pop_back(){
            if(head->next == nullptr)
            {
                auto val = head->data;
                delete head;
                head = nullptr;
                return val;
            }
            else {
                auto it = head;
                while (it->next->next != nullptr)
                    it = it->next;
                T val = it->next->data;
                delete it->next;
                it->next = nullptr;
                return val;
            }
            //throw ("sin definir");
        }

        T insert(T data, int pos){
            auto nuevo = new Node<T>(data);
            if(pos == 0){
                nuevo->next = head;
                head = nuevo;
            }
            else if(pos == size()){
                auto it = head;
                while (it->next != nullptr)
                    it = it->next;
                it->next = nuevo;
                nuevo->next = nullptr;
            }
            else{
                auto temp = head;
                for (int i = 0; i < pos; ++i) {
                    temp = temp->next;
                }
                nuevo->next = temp->next;
                temp->next = nuevo;
            }
            return nuevo->data;
            //throw ("sin definir");
        }

        void remove(int pos){
            auto temp = head;
            if(pos == 0){
                head = head->next;
                delete temp;
            }
            else if(pos == size()){
                while (temp->next->next != nullptr)
                    temp = temp->next;
                delete temp->next;
                temp->next = nullptr;
            }
            else{
                auto temp2 = temp->next;
                for (int i = 0; i < pos-1; ++i){
                    temp = temp->next;
                    temp2 = temp->next;
                }
                temp->next = temp2->next;
                delete temp2;
            }
            //throw ("sin definir");
        }

        T& operator[](int pos){
            auto temp = head;
            for (int i = 0; i < pos; ++i) {
                temp = temp->next;
            }
            return temp->data;
            //throw ("sin definir");
        }

        bool is_empty(){
            //return head == reinterpret_cast<int>(nullptr); //esto no funciona, pero deberia, no se que pasa!!!
            return true;
            //throw ("sin definir");
        }

        int size(){
            int cont = 0;
            for (auto it = head; it->next != nullptr; it = it->next){
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
                for(auto it = head; it->next != nullptr; it = it->next){
                    delete it;
                }
            }
            head = nullptr;
            //throw ("sin definir");
        }
        
        void sort(){
            if (is_empty() || size()==1){
                return;
            }
            else{
                Node<T>* sorted = nullptr;
                auto temp1 = head;
                while(temp1 != nullptr){
                    if (sorted == nullptr || sorted->data >= temp1->data) {
                        temp1->next = sorted;
                        sorted = temp1;
                    }
                    else {
                        Node<T>* temp2 = sorted;
                        while (temp2->next != nullptr && temp2->next->data < temp1->data){
                            temp2 = temp2->next;
                        }
                        temp1->next = temp2->next;
                        temp2->next = temp1;
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
            Node<T>* prev = nullptr;
            Node<T>* next = nullptr;

            while (it != nullptr) {
                next = it->next;
                it->next = prev;
                prev = it;
                it = next;
            }
            head = prev;
            //throw ("sin definir");
        }

        string name(){
            return "ForwardList";
        }
        
};

#endif