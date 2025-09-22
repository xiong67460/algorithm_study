#include <bits/stdc++.h>
using namespace std;
class maxHeap
{
private:
    vector<int> heap;

public:
    maxHeap(vector<int> vec)
    {
        heap = vec;
        for (int i = parent(size() - 1); i >= 0; i--)
        {
            siftdown(i);
        }
    }
    int size()
    {
        return heap.size();
    }
    bool isempty()
    {
        return size() == 0;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int peek()
    {
        return heap[0];
    }
    void siftup(int i)
    {
        while (1)
        {
            int p = parent(i);
            if (p < 0 || heap[i] <= heap[p])
                break;
            swap(heap[i], heap[p]);
            i = p;
        }
    }
    void push(int val)
    {
        heap.push_back(val);
        siftup(size() - 1);
    }
    void siftdown(int i)
    {
        while (1)
        {
            int l = left(i), r = right(i), ma = i;
            if (l < size() && heap[l] > heap[ma])
                ma = l;
            if (r < size() && heap[r] > heap[ma])
                ma = r;
            if (ma == i)
                break;
            swap(heap[i], heap[ma]);
            i = ma;
        }
    }
    void pop()
    {
        if (isempty())
            throw out_of_range("堆为空");
        swap(heap[0], heap[size() - 1]);
        heap.pop_back();
        siftdown(0);
    }
};
