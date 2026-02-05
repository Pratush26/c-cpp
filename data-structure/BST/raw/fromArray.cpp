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

void levelOrder(Node* root){
        queue<Node*> q;
        if(root) q.push(root);
        while (!q.empty()){
            Node* current = q.front();
            cout << current->val << " ";
            q.pop();
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
}

Node* ArrToBst(vector<int>& arr, int s, int e){
    if(s>e) return NULL;
    int mid = (s+e)/2;
    Node* root = new Node(arr[mid]);
    Node* leftNode = ArrToBst(arr, s, mid-1);
    Node* rightNode = ArrToBst(arr, mid+1, e);
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    Node *root = ArrToBst(arr, 0, arr.size()-1);
    levelOrder(root);
    return 0;
}