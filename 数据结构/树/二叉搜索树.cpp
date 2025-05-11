#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
TreeNode *search(int num, TreeNode *root)
{
    TreeNode *cur = root;
    while (cur != nullptr)
    {
        if (cur->val < num)
            cur = cur->right;
        else if (cur->val > num)
            cur = cur->left;
        else
            break;
    }
    return cur;
}
void insert_A(int num, TreeNode *&root)
{
    if (root == nullptr)
    {
        root = new TreeNode(num);
        return;
    }
    TreeNode *cur = root, *pre = nullptr;
    while (cur != nullptr)
    {
        if (cur->val == num)
            return;
        pre = cur;
        if (cur->val < num)
            cur = cur->right;
        else
            cur = cur->left;
    }
    TreeNode *node = new TreeNode(num);
    if (pre->val < num)
        pre->right = node;
    else
        pre->left = node;
}
TreeNode *insert_B(int num, TreeNode *root)
{
    if (root == nullptr)
    {
        return new TreeNode(num);
    }

    if (num < root->val)
    {
        root->left = insert_B(num, root->left);
    }
    else if (num > root->val)
    {
        root->right = insert_B(num, root->right);
    }
    return root;
}
