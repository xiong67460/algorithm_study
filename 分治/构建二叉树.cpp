// 根据前序和中序遍历构建二叉树
#include "../utils/common.hpp"
using namespace std;
/*struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};*/
TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorderMap, int i, int l, int r)
{
    if (r - l < 0)
        return NULL;
    TreeNode *root = new TreeNode(preorder[i]);
    int m = inorderMap[preorder[i]];
    root->left = dfs(preorder, inorderMap, i + 1, l, m - 1);
    root->right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++)
        inorderMap[inorder[i]] = i;
    TreeNode *root = dfs(preorder, inorderMap, 0, 0, preorder.size() - 1);
    return root;
}
int main()
{
    int n;
    cin >> n;
    vector<int> pre(n);
    vector<int> in(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    for (int i = 0; i < n; i++)
        cin >> in[i];
    TreeNode *root = buildTree(pre, in);
    printTree(root);
    return 0;
}