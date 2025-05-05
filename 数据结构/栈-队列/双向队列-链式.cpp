#include <bits/stdc++.h>
using namespace std;
struct DoublyListNode
{
    int val;
    DoublyListNode *next;
    DoublyListNode *prev;
    DoublyListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
};
class LinkedListDeque
{
private:
    DoublyListNode *front, *rear;
    int queSize = 0;

public:
    LinkedListDeque()
    {
        front = rear = nullptr;
        queSize = 0;
    }
    ~LinkedListDeque()
    {
        DoublyListNode *pre, *cur = front;
        while (cur != nullptr)
        {
            pre = cur;
            cur = cur->next;
            delete pre;
        }
    }
    int size()
    {
        return queSize;
    }
    bool  isempty()
    {
        return size() == 0;
    }
    int peekFirst()
    {
        if (isempty())
            throw out_of_range("双向队列为空");
        return front->val;
    }
    int peekLast()
    {
        if (isempty())
            throw out_of_range("双向队列为空");
        return rear->val;
    }
    int pop(bool isFront)
    {
        if (isempty())
            throw out_of_range("队列为空");
        int val;
        if (isFront)
        {
            val = front->val;
            DoublyListNode *fNext = front->next;
            if (fNext != nullptr)
            {
                fNext->prev = nullptr;
                front->next = nullptr;
            }
            delete front;
            front = fNext;
        }
        else
        {
            val = rear->val;
            DoublyListNode *rPrev = rear->prev;
            if (rPrev != nullptr)
            {
                rPrev->next = nullptr;
                rear->prev = nullptr;
            }
            delete rear;
            rear = rPrev;
        }
        queSize--;
        return val;
    }
    int popFirst()
    {
        return pop(true);
    }
    int popLast()
    {
        return pop(false);
    }
    void push(int num, bool isFront)
    {
        DoublyListNode *node = new DoublyListNode(num);
        if (isempty())
            front = rear = node;
        else if (isFront)
        {
            node->next = front;
            front->prev = node;
            front = node;
        }
        else
        {
            node->prev = rear;
            rear->next = node;
            rear = node;
        }
        queSize++;
    }
    void pushFirst(int num)
    {
        push(num, true);
    }
    void pushLast(int num)
    {
        push(num, false);
    }
    vector<int> tovector()
    {
        DoublyListNode *node = front;
        vector<int> res(queSize);
        for (int i = 0; i < queSize;i++){
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};
