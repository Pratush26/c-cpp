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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void insert_tail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void reverseSingly(Node* &head, Node* &tail, Node* &temp){
    if(temp->next == NULL) {
        tail = temp;
        return;
    }
    return reverseSingly(head, temp->next);

}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insert_tail(head, tail, 10);
    insert_tail(head, tail, 20);
    insert_tail(head, tail, 30);
    insert_tail(head, tail, 40);
    insert_tail(head, tail, 50);
    print_list(head);

    return 0;
}
