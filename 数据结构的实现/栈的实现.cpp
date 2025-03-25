#include <bits/stdc++.h>
#define max 100
using namespace std;

typedef struct
{
    int data[max];
    int top;
} Stack;

void init(Stack &s)
{
    s.top = -1;
}

int isfull(const Stack &s)
{
    return s.top == max - 1;
}

void empty(const Stack &s)
{
    if (s.top == -1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}

void size(const Stack &s)
{
    printf("%d\n", s.top + 1);
}

void push(Stack &s, int x)
{
    if (isfull(s))
    {
        printf("ERROR\n");
    }
    else
    {
        s.data[s.top + 1] = x;
        s.top++;
    }
}

void pop(Stack &s)
{
    if (s.top == -1)
    {
        printf("ERROR\n");
    }
    else
    {
        s.top--;
    }
}

void top(const Stack &s)
{
    if (s.top == -1)
    {
        printf("ERROR\n");
    }
    else
    {
        printf("%d\n", s.data[s.top]);
    }
}

void clear(Stack &s)
{
    s.top = -1;
}

int main()
{
    Stack s;
    init(s);
    int T;
    cin >> T;
    string op;
    int x;
    while (T--)
    {
        cin >> op;
        if (op == "push")
        {
            cin >> x;
            push(s, x);
        }
        else if (op == "pop")
        {
            pop(s);
        }
        else if (op == "top")
        {
            top(s);
        }
        else if (op == "size")
        {
            size(s);
        }
        else if (op == "clear")
        {
            clear(s);
        }
        else if (op == "empty")
        {
            empty(s);
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }
}
