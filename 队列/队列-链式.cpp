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
class LinkedListQueue
{
private:
    int queSize;
    ListNode *front, *rear;

public:
    LinkedListQueue()
    {
        front = rear = nullptr;
        queSize = 0;
    }
    ~LinkedListQueue()
    {
        freeMemoryLinkedList(front);
    }
    int size()
    {
        return queSize;
    }
    bool isempty()
    {
        return size() == 0;
    }
    int peek()
    {
        if (isempty())
            throw out_of_range(" ╤сапн╙©у");
        return front->val;
    }
    int pop()
    {
        int num = peek();
        ListNode *tmp = front;
        front = front->next;
        delete tmp;
        queSize--;
        return num;
    }
    void push(int num)
    {
        ListNode *node = new ListNode(num);
        if (front == nullptr)
        {
            front = node;
            rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
        queSize++;
    }
    vector<int> tovector()
    {
        ListNode *node = front;
        vector<int> res(size());
        for (int i = 0; i < size(); i++)
        {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};
int main()
{
    LinkedListQueue s;
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
    for (int num : arr)
        cout << num << " ";
    return 0;
}
