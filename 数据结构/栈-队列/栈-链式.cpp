#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
void freeMemoryLinkedList(ListNode *head)
{
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}

class LinkedListStack
{
private:
    ListNode *stackTop;
    int stksize;

public:
    LinkedListStack()
    {
        stackTop = nullptr;
        stksize = 0;
    }
    ~LinkedListStack()
    {
        freeMemoryLinkedList(stackTop);
    }
    int size()
    {
        return stksize;
    }
    bool isempty()
    {
        return size() == 0;
    }
    int top()
    {
        if (isempty())
            throw out_of_range(" Õ»Îª¿Õ");
        return stackTop->val;
    }
    int pop()
    {
        int num = top();
        ListNode *tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
        stksize--;
        return num;
    }
    void push(int num)
    {
        ListNode *node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stksize++;
    }
    vector<int> tovector()
    {
        ListNode *node = stackTop;
        vector<int> res(size());
        for (int i = size() - 1; i >= 0; i--)
        {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};
int main()
{
    LinkedListStack s;
    int n, m;

    cin >> n;
    while (n--)
    {
        cin >> m;
        s.push(m);
    }
    cout << s.size() << '\n';
    cout << s.pop() << '\n';
    cout << s.pop() << '\n';
    cout << s.size() << '\n';
    vector<int> arr = s.tovector();
    for(int num:arr)
        cout << num << " ";
    return 0;
}