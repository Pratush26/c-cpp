#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input(){
    queue<Node*> q;
    int l, r, val;
    cin >> val;
    Node *root = nullptr;
    if(val != -1){
        root = new Node(val);
        q.push(root);
    }
    while (!q.empty()){
        Node *leftNode = nullptr, *rightNode = nullptr, *current = q.front();
        cin >> l >> r;
        if(l != -1) leftNode = new Node(l);
        if(r != -1) rightNode = new Node(r);
        current->left = leftNode;
        current->right = rightNode;
        q.pop();
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
    return root;
}

Node* insert(Node* root, int val) {
    if (!root){
         return new Node(val);
    }
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

bool search(Node *root, int x){
    if (root == NULL) return false;
    if (root->val == x) return true;

    return x < root->val ? search(root->left, x) : search(root->right, x);
}

int main() {
    int val;
    Node *root = input();
    // 20 10 30 5 15 25 35 -1 -1 12 19 -1 -1 -1 -1 -1 -1 -1 -1

    cin >> val;
    cout << (search(root, val) ? "Found\n" : "Not found!\n");
    root = insert(root, 34);
    return 0;
}