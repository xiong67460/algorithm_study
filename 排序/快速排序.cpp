#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &nums, int left, int right)
{
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && nums[j] >= nums[left])
            j--;
        while (i < j && nums[i] <= nums[left])
            i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    return i;
}

void Sort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int pivot = partition(nums, left, right);
    Sort(nums, left, pivot - 1);
    Sort(nums, pivot + 1, right);
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
    Sort(nums, 0, m - 1);
    for (int i = 0; i < m; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}