#include <bits/stdc++.h>
using namespace std;

class ArrayDeque
{
private:
    vector<int> nums;
    int front;
    int queSize;

public:
    ArrayDeque(int capacity)
    {
        nums.resize(capacity);
        front = queSize = 0;
    }
    int capacity()
    {
        return nums.size();
    }
    int size()
    {
        return queSize;
    }
    bool isempty()
    {
        return size() == 0;
    }
    int index(int i)
    {
        return (i + capacity()) % capacity();
    }
    int peekFirst()
    {
        if (isempty())
            throw out_of_range("双向队列为空");
        return nums[front];
    }
    int peekLast()
    {
        if (isempty())
            throw out_of_range("双向队列为空");
        int last = index(front + queSize - 1);
        return nums[last];
    }
    int popLast()
    {
        int num = peekLast();
        queSize--;
        return num;
    }
    int popFirst()
    {
        int num = peekFirst();
        front = index(front + 1);
        queSize--;
        return num;
    }
    void pushFirst(int num)
    {
        if (queSize == capacity())
        {
            cout << "双向队列已满" << '\n';
            return;
        }
        front = index(front - 1);
        nums[front] = num;
        queSize++;
    }
    void pushLast(int num)
    {
        if (queSize == capacity())
        {
            cout << "双向队列已满" << '\n';
            return;
        }
        int rear = index(front + queSize);
        nums[rear] = num;
        queSize++;
    }
    vector<int> tovector()
    {
        vector<int> res(queSize);
        for (int i = 0, j = front; i < queSize; i++, j++)
            res[i] = nums[index(j)];
        return res;
    }
};
