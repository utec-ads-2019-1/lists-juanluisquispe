#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"
#include "node.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            if(List<T>::head == nullptr) throw(out_of_range("Segmentation Fault"));
            return List<T>::head -> data;
        }

        T back() {
            if(List<T>::tail == nullptr) throw(out_of_range("Segmentation Fault"));
            return List<T>::tail -> data;
        }

        void push_front(T value) {
            List<T>::head = new Node<T>(value , List<T>::head , nullptr);
            if(nodes == 0)
                List<T>::tail = List<T>::head;
            if(nodes == 1)
                List<T>::tail = List<T>::head->next;
            List<T>::nodes++;
        }

        void push_back(T value) {
            Node<T>* prevtail = List<T>::tail;
            List<T>::tail = new Node<T>(value , nullptr , nullptr);
            if(nodes == 0)
                List<T>::head = List<T>::tail;
            else
                prevtail->next = List<T>::tail;
            List<T>::nodes++;
        }

        void pop_front() {
            Node<T>* prevhead = List<T>::head;
            List<T>::head->killSelf();
            List<T>::head = prevhead->next;
            List<T>::nodes--;
        }

        void pop_back() {
            Node<T>* it = List<T>::head;
            List<T>::tail->killSelf();
            for(int i = 0 ; i < nodes-1 ; i++){
                it = it->next;
            }
            List<T>::tail = it;
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
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            ForwardIterator<T> = List<T>::head;
        }

	    ForwardIterator<T> end() {
            ForwardITerator<T> = List<T>::tail;
        }

        void merge(ForwardList<T> list) {
            // TODO
        }
};

#endif