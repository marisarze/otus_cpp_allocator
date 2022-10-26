#include "linked_list.h"


template <typename T>
void StackLinkedList<T>::push(Node * newNode) {
    newNode->next = head;
    head = newNode;
}


template <typename T>
typename StackLinkedList<T>::Node* StackLinkedList<T>::pop() {
    Node * top = head;
    head = head->next;
    return top;
}