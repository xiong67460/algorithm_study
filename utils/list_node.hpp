/**
 * File: list_node.hpp
 * Created Time: 2021-12-19
 * Author: krahets (krahets@163.com)
 */

#pragma once

#include <iostream>
#include <vector>

using namespace std;

/* ����ڵ� */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};

/* ���б����л�Ϊ���� */
ListNode *vecToLinkedList(vector<int> list)
{
    ListNode *dum = new ListNode(0);
    ListNode *head = dum;
    for (int val : list)
    {
        head->next = new ListNode(val);
        head = head->next;
    }
    return dum->next;
}

/* �ͷŷ����������ڴ�ռ� */
void freeMemoryLinkedList(ListNode *cur)
{
    // �ͷ��ڴ�
    ListNode *pre;
    while (cur != nullptr)
    {
        pre = cur;
        cur = cur->next;
        delete pre;
    }
}
