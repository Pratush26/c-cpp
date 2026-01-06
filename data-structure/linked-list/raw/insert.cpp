#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print_list(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}
void insert_head(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
void insert_tail(Node* head, int data){
    Node* newNode = new Node(data);
    if(head == NULL) head = newNode;
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
void insert_pos(Node* head, int pos, int data){
    Node* newNode = new Node(data);
    if(head == NULL) head = newNode;
    Node* temp = head;
    for (int i = 1; i < pos; i++) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}
int main() {
    Node* head = new Node(100);
    Node* a = new Node(200);
    Node* b = new Node(300);
    head->next = a;
    a->next = b;
    insert_head(head, 1000);
    insert_tail(head, 1000);
    insert_pos(head, 2, 5000);
    print_list(head);
    return 0;
}