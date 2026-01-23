#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void levelOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* current = q.front();
        cout << current->val << " ";
        q.pop();
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}
TreeNode* input(){
    queue<TreeNode*> q;
    int l, r, val;
    cin >> val;
    TreeNode *root = new TreeNode(val);
    q.push(root);
    while (!q.empty()){
        TreeNode *leftNode = nullptr, *rightNode = nullptr, *current = q.front();
        cin >> l >> r;
        if(l != -1) leftNode = new TreeNode(l);
        if(r != -1) rightNode = new TreeNode(r);
        current->left = leftNode;
        current->right = rightNode;
        q.pop();
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
    return root;
}

int main(){
    TreeNode *root = input();
    // 1 10 20 100 -1 200 300 -1 -1 -1 -1 -1 -1

    levelOrder(root);
    return 0;
}