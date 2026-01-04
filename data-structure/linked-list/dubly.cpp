#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_forward(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void print_backward(Node* tail){
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";
}

void insert_head(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_tail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insert_pos(Node* &head, Node* &tail, int pos, int data){
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    Node* temp = head;
    for (int i = 1; i < pos; i++) temp = temp->next;
    newNode->next = temp->next;
    newNode->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void delete_head(Node* &head, Node* &tail){
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    if(head == NULL) tail = NULL;
    else head->prev = NULL;
    delete temp;
}

void delete_tail(Node* &head, Node* &tail){
    if (tail == NULL) return;
    Node* temp = tail;
    tail = temp->prev;
    if(tail == NULL) head = NULL;
    else tail->next = NULL;
    delete temp;
}

void delete_pos(Node* &head, Node* &tail, int pos){
    if (head == NULL || pos < 0) return;
    Node* temp = head;
    if (pos == 0) {
        head = head->next;
        if(head == NULL) tail = NULL;
        else head->prev = NULL;
        delete temp;
        return;
    }
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
        if(temp == NULL) return;
    }
    Node* target = temp->next;
    if (target == NULL) return;
    if (target == tail) {
        tail = tail->prev;
        tail->next = NULL;
        delete target;
        return;
    }
    temp->next = target->next;
    target->next->prev = temp;
    delete target;
}

int main() {
    Node* head = new Node(300);
    Node* tail = new Node(900);
    head->next = tail;
    tail->prev = head;
    insert_head(head, tail, 100);
    insert_tail(head, tail, 1000);
    insert_pos(head, tail, 2, 500);
    delete_pos(head, tail, 4);
    print_forward(head);
    print_backward(tail);
    return 0;
}