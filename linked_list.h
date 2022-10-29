#pragma once

template <typename T>
class StackLinkedList {
public:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

    StackLinkedList() = default;
    StackLinkedList(StackLinkedList<T>& StackLinkedList) = delete;
    void push(Node* newNode);
    Node* pop();
};


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