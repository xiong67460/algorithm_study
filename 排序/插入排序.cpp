#include <bits/stdc++.h>
using namespace std;
void Sort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int base = nums[i], j = i - 1;
        while (j >= 0 && nums[j] > base)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
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