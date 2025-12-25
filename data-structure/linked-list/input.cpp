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
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    int elem;
    while (1){
        cin >> elem;
        if(elem == -1) break;
        insert_tail(head, tail, elem);
    }
    print_list(head);
    return 0;
}
