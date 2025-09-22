#include <bits/stdc++.h>
using namespace std;
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinklist;
bool ListInsert(DLinklist &L, int i, int e)
{
    DNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
}
bool ListDelete(DLinklist &L, int i, int &e)
{
    DNode *p = L;
    int j = 0;
    while (p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j > i - 1)
        return false;
    DNode *q = p->next;
    e = q->data;
    p->next = q->next;
    q->next->prior = q;
    free(q);
    return true;
}