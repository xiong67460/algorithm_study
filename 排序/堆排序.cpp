#include <bits/stdc++.h>
using namespace std;
void siftDown(vector<int> &nums, int n, int i)
{
    while (1)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int ma = i;
        if (l < n && nums[l] > nums[ma])
            ma = l;
        if (r < n && nums[r] > nums[ma])
            ma = r;
        if (ma == i)
            break;
        swap(nums[i], nums[ma]);
        i = ma;
    }
}
void Sort(vector<int> &nums)
{
    for (int i = nums.size() / 2 - 1; i >= 0; i--)
        siftDown(nums, nums.size(), i);
    for (int i = nums.size() - 1; i > 0; i--)
    {
        swap(nums[0], nums[i]);
        siftDown(nums, i, 0);
    }
}
int main()
{
    int m;
    cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums[i];
    }
    Sort(nums);
    for (int i = 0; i < m; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}