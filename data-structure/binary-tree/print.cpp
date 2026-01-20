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
void preOrder(TreeNode* root){
        if(!root) return;
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
}

void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
}
void postOrder(TreeNode* root){
        if(!root) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val << " ";
}

int main(){
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(10);
    TreeNode *p2 = new TreeNode(20);
    TreeNode *c1 = new TreeNode(100);
    TreeNode *c2 = new TreeNode(200);
    TreeNode *c3 = new TreeNode(300);

    root->left = p1;
    root->right = p2;

    p1->left = c1;
    p2->left = c2;
    p2->right = c3;

    preOrder(root);
    cout << "\n";

    inOrder(root);
    cout << "\n";

    postOrder(root);
    return 0;
}