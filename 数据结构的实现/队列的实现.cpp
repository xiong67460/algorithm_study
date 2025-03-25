#include <bits/stdc++.h>
#define max 100
using namespace std;
typedef struct
{
    int data[max];
    int front;
    int rear;
} Queue;
void init(Queue &q)
{
    q.front = 0;
    q.rear = 0;
}
void empty(Queue &q)
{
    if (q.front == q.rear)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
void size(Queue &q)
{
    cout << q.rear - q.front << endl;
}
void clear(Queue &q)
{
    q.front = 0;
    q.rear = 0;
}
void push(Queue &q, int x)
{
    if (q.rear < max)
        q.data[q.rear++] = x;
    else
        cout << "ERROR" << endl;
}
void pop(Queue &q)
{
    if (q.front != q.rear)
        q.front++;
    else
        cout << "ERROR" << endl;
}
void front(Queue &q)
{
    if (q.front != q.rear)
        cout << q.data[q.front] << endl;
    else
        cout << "ERROR" << endl;
}
void swap(Queue &a, Queue &b)
{
    Queue temp = a;
    a = b;
    b = temp;
}
void func(Queue &a, Queue &b)
{
    b.front = 0;
    b.rear = 0;
    for (int i = a.front; i < a.rear; i++)
    {
        push(b, a.data[i]);
    }
}
int main()
{
    int T;
    cin >> T;
    Queue a, b;
    init(a);
    init(b);
    string op;
    int x;
    while (T--)
    {
        cin >> op;
        if (op == "swap")
        {
            swap(a, b);
        }
        else if (op == "pop")
        {
            cin >> op;
            if (op == "a")
                pop(a);
            else
                pop(b);
        }
        else if (op == "front")
        {
            cin >> op;
            if (op == "a")
                front(a);
            else
                front(b);
        }
        else if (op == "size")
        {
            cin >> op;
            if (op == "a")
                size(a);
            else
                size(b);
        }
        else if (op == "empty")
        {
            cin >> op;
            if (op == "a")
                empty(a);
            else
                empty(b);
        }
        else if (op == "clear")
        {
            cin >> op;
            if (op == "a")
                clear(a);
            else
                clear(b);
        }
        else if (op == "push")
        {
            cin >> op >> x;
            if (op == "a")
                push(a, x);
            else
                push(b, x);
        }
        else if (op == "operator=")
        {
            cin >> op;
            if (op == "a")
                func(a, b);
            else
                func(b, a);
        }
    }
}