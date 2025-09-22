// 简单实现-只能排序非负数
#include <bits/stdc++.h>
using namespace std;
void Sort(vector<int> &nums)
{
    int m = 0;
    for (int num : nums)
    {
        m = max(m, num);
    }
    vector<int> counter(m + 1, 0);
    for (int num : nums)
    {
        counter[num]++;
    }
    int i = 0;
    for (int num = 0; num <= m; num++)
    {
        for (int j = 0; j < counter[num]; j++, i++)
        {
            nums[i] = num;
        }
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