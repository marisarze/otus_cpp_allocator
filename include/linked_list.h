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
