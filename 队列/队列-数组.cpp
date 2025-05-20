#include <bits/stdc++.h>
using namespace std;
class ArrayQueue
{
private:
    int *nums;
    int front;
    int queCapacity;
    int queSize;

public:
    ArrayQueue(int capacity)
    {
        nums = new int[capacity];
        queCapacity = capacity;
        front = queSize = 0;
    }
    ~ArrayQueue()
    {
        delete[] nums;
    }
    int capacity()
    {
        return queCapacity;
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
            throw out_of_range("队列为空");
        return nums[front];
    }
    int pop()
    {
        int num = peek();
        front = (front + 1) % queCapacity;
        queSize--;
        return num;
    }
    void push(int num)
    {
        if (queSize == queCapacity)
        {
            cout << " 队列已满" << endl;
            return;
        }
        int rear = (front + queSize) % queCapacity;
        nums[rear] = num;
        queSize++;
    }
    vector<int> tovector()
    {
        vector<int> arr(queSize);
        for (int i = 0, j = front; i < queSize; i++, j++)
            arr[i] = nums[j % queCapacity];
        return arr;
    }
};
int main()
{
    ArrayQueue s(30);
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
