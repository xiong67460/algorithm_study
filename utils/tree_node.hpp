/**
 * File: tree_node.hpp
 * Created Time: 2021-12-19
 * Author: krahets (krahets@163.com)
 */

#pragma once

#include <limits.h>
#include <vector>

using namespace std;

/* �������ڵ�ṹ�� */
struct TreeNode
{
    int val{};
    int height = 0;
    TreeNode *parent{};
    TreeNode *left{};
    TreeNode *right{};
    TreeNode() = default;
    explicit TreeNode(int x, TreeNode *parent = nullptr) : val(x), parent(parent)
    {
    }
};

// ���л����������ο���
// https://www.hello-algo.com/chapter_tree/array_representation_of_tree/
// �������������ʾ��
// [1, 2, 3, 4, None, 6, 7, 8, 9, None, None, 12, None, None, 15]
// �������������ʾ��
//             /������ 15
//         /������ 7
//     /������ 3
//    |    \������ 6
//    |        \������ 12
// ������ 1
//     \������ 2
//        |    /������ 9
//         \������ 4
//             \������ 8

/* ���б����л�Ϊ���������ݹ� */
TreeNode *vectorToTreeDFS(vector<int> &arr, int i)
{
    if (i < 0 || i >= arr.size() || arr[i] == INT_MAX)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(arr[i]);
    root->left = vectorToTreeDFS(arr, 2 * i + 1);
    root->right = vectorToTreeDFS(arr, 2 * i + 2);
    return root;
}

/* ���б����л�Ϊ������ */
TreeNode *vectorToTree(vector<int> arr)
{
    return vectorToTreeDFS(arr, 0);
}

/* �����������л�Ϊ�б��ݹ� */
void treeToVecorDFS(TreeNode *root, int i, vector<int> &res)
{
    if (root == nullptr)
        return;
    while (i >= res.size())
    {
        res.push_back(INT_MAX);
    }
    res[i] = root->val;
    treeToVecorDFS(root->left, 2 * i + 1, res);
    treeToVecorDFS(root->right, 2 * i + 2, res);
}

/* �����������л�Ϊ�б� */
vector<int> treeToVecor(TreeNode *root)
{
    vector<int> res;
    treeToVecorDFS(root, 0, res);
    return res;
}

/* �ͷŶ������ڴ� */
void freeMemoryTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    freeMemoryTree(root->left);
    freeMemoryTree(root->right);
    delete root;
}
