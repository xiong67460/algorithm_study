#include <bits/stdc++.h>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
bool Initlist(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    return true;
}
bool Initlist_Nohead(LinkList &L)
{
    L = NULL;
    return true;
}
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}
LNode *GetElem(LinkList L, int i)
{
    LNode *p = L;
    int j = 0;
    while (p != 0 && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}
bool ListInsert(LinkList &L, int i, int e)
{
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool ListDelete(LinkList &L, int i, int &e)
{
    LNode *p = L;
    int j = 0;
    while (p->next != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j > i - 1)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    cin >> x;
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    LNode *s, *r = L;
    cin >> x;
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
    return L;
}
int main()
{
    LinkList L;
    Initlist(L);
    List_TailInsert(L);
    cout << Length(L) << endl;
    cout << GetElem(L, 1)->data << endl;
    ListInsert(L, 1, 2);
    cout << Length(L) << endl;
    cout << GetElem(L, 3)->data;
}