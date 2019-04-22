#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
            if(List<T>::head == nullptr) throw(out_of_range("Segmentation Fault"));
            return List<T>::head -> data;
        }

        T back() {
            if(List<T>::tail == nullptr) throw(out_of_range("Segmentation Fault"));
            return List<T>::tail -> data;
        }

        void push_front(T value) {
            Node<T>* it = List<T>::head;
            List<T>::head = new Node<T>(value , List<T>::head , nullptr);
            if(nodes == 0)
                List<T>::tail = List<T>::head;
            else
                it->prev = List<T>::head;
            List<T>::nodes++;
        }

        void push_back(T value) {
            Node<T>* it = List<T>::tail;
            List<T>::tail = new Node<T>(value , nullptr , List<T>::tail);
            if(nodes == 0)
                List<T>::head = List<T>::tail;
            else
                it->next = List<T>::tail;
            List<T>::nodes++;
        }

        void pop_front() {
            Node<T>* it = List<T>::head;
            List<T>::head = List<T>::head->next;
            it->killSelf();
            List<T>::head->prev = nullptr;
            List<T>::nodes--;
        }

        void pop_back() {
            Node<T>* it = List<T>::tail;
            List<T>::tail = List<T>::tail->prev;
            it->killSelf();
            List<T>::tail->next = nullptr;
            List<T>::nodes--;
        }

        T operator[](int index) {
            Node<T>* it = List<T>::head;
            for(int i = 0 ; i <= index ; i++){
                it = it->next;
            }
            return it->data;
        }

        bool empty() {
            if(nodes == 0)
                return true;
            else
                return false;
        }

        int size() {
            return List<T>::nodes;
        }

        void clear() {
            List<T>* it = List<T>::head;
            List<T>* it2;
            for(int i = 0 ; i <= nodes ; i++){
                it2 = it->next;
                it->killSelf();
                it = it2;
            }
            List<T>::head = nullptr;
            List<T>::tail = nullptr;
            List<T>::nodes = 0;
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            // TODO
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(LinkedList<T> list) {
            // TODO
        }
};

#endif