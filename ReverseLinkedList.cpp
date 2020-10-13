// ReverseLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
}node;

void insertNode(node *& head, int data )
{
    node* temp = nullptr;

    if (head == nullptr)
    {
        head = new node();
        head->data = data;
        head->next = nullptr;
        return;
    }

    temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = new node();
    temp->next->data = data;
    temp->next->next = nullptr;

    return;
}

void printList(node*& head)
{
    node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }

    cout << endl;
    return;
}

void reverseList(node*& head)
{
    if (head == nullptr)
        return;
    if (head->next == nullptr)
        return;

    node* prev = nullptr, * curr = nullptr, * next = nullptr;

    curr = head;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int main()
{
    node* head = nullptr;
    for (int i = 1; i <= 10; i++)
        insertNode(head, i);
    printList(head);
    reverseList(head);
    printList(head);
    return 0;
}

