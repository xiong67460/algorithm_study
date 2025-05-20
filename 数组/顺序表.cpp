#include <bits\stdc++.h>
#define MaxSize 10
struct SQList
{
    int data[MaxSize];
    int length;
};
void InitList(SQList &L)
{
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}
bool ListInsert(SQList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length > MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i] = e;
    L.length++;
    return true;
}
bool ListDelete(SQList &L, int i, int &e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}
int GetElem(SQList L, int i)
{
    return L.data[i - 1];
}
int LocateElem(SQList L, int e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

