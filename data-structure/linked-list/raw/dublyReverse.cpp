#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_forward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void insert_tail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void reverseDubly(Node* &head, Node* &tail){
    Node* start = head, * end = tail;
    while ((start != end) && (start->prev != end))
    {
        swap(start->data, end->data);
        start = start->next;
        end = end->prev;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    head->next = tail;
    tail->prev = head;
    insert_tail(head, tail, 10);
    insert_tail(head, tail, 20);
    insert_tail(head, tail, 30);
    insert_tail(head, tail, 40);
    insert_tail(head, tail, 50);
    print_forward(head);
    reverseDubly(head, tail);
    print_forward(head);
    return 0;
}