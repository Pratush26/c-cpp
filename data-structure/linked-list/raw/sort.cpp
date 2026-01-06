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
// using selection sort
void sort_list(Node* head){
    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if(i->data > j->data) swap(i->data, j->data);
        }
        
    }
}
int main() {
    Node* head = new Node(100);
    insert_head(head, 40);
    insert_head(head, 200);
    insert_head(head, 70);
    insert_head(head, 90);
    sort_list(head);
    print_list(head);
    return 0;
}