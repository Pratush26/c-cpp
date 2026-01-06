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

int main() {
    Node head(100), a(200);
    head.next = &a;
    cout << head.data << endl;
    cout << head.next->data << endl;
    return 0;
}