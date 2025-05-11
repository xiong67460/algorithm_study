#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

/*层序遍历  BFS*/
vector<int> levelOrder(TreeNode *root)
{
    queue<TreeNode *> queue;
    queue.push(root);
    vector<int> vec;
    while (!queue.empty())
    {
        TreeNode *node = queue.front();
        queue.pop();
        vec.push_back(node->val);
        if (node->left != nullptr)
            queue.push(node->left);
        if (node->right != nullptr)
            queue.push(node->right);
    }
    return vec;
}

/*前中后序遍历 DFS*/
/*前序*/
void preOrder(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr)
        return;
    vec.push_back(root->val);
    preOrder(root->left, vec);
    preOrder(root->right, vec);
}
/*中序*/
void inOrder(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr)
        return;
    preOrder(root->left, vec);
    vec.push_back(root->val);
    preOrder(root->right, vec);
}
/*后序*/
void postOrder(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr)
        return;
    preOrder(root->left, vec);
    preOrder(root->right, vec);
    vec.push_back(root->val);
}

int main()
{
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    vector<int> arr;
    inOrder(n1, arr);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << '\n';
    }
    /*
    TreeNode *p = new TreeNode(0); // insert p;
    n1->left = p;
    p->left = n2;
    n1->left = n2; // remove p;
    */
    return 0;
}