#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> topHeap(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < k; i++)
        heap.push(nums[i]);
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > heap.top())
        {
            heap.pop();
            heap.push(nums[i]);
        }
    }
    return heap;
}
int main()
{
    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cin >> k;
    priority_queue<int, vector<int>, greater<int>> heap = topHeap(nums, k);
    while (!heap.empty())
    {
        cout << heap.top() << '\n';
        heap.pop();
    }
    return 0;
}
