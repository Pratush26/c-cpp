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
int CountNode(TreeNode* root){
    if(!root) return 0;
    int l = CountNode(root->left);
    int r = CountNode(root->right);
    return l+r+1;
}
int height(TreeNode* root){
    if(!root) return 0;
    if(!root->left && !root->right) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l,r)+1;
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

    int s = CountNode(root);
    cout << "Tree size: " << s << "\n";
    int ls = height(root);
    cout << "Tree height: " << ls << "\n";
    return 0;
}