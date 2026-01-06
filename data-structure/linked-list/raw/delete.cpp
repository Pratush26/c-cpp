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

void delete_node(Node* &head, Node* &tail, int pos){
    if (head == NULL) return;
    if(pos == 0){
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        if (head == NULL) tail = NULL;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pos-1; i++) {
        temp = temp->next;
        if(temp == NULL) return;
    }
    if(temp->next == NULL) return;
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    if (temp->next == NULL) tail = temp;
    delete deleteNode;
}

void insert_tail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int elem, v;
    while (1){
        cin >> elem;
        if(elem == -1) break;
        insert_tail(head, tail, elem);
    }
    cin >> v;
    delete_node(head, tail, v);
    return 0;
}