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
int main(){
    TreeNode *root = new TreeNode(10);
    TreeNode *c1 = new TreeNode(100);
    TreeNode *c2 = new TreeNode(200);
    root->left = c1;
    root->right = c2;
    return 0;
}