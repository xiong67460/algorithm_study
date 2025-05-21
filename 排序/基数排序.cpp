//·Ç¸ºÊýÅÅÐò
#include <bits/stdc++.h>
using namespace std;
int digit(int num, int exp)
{
    return (num / exp) % 10;
}
void countingSortDigit(vector<int> &nums, int exp)
{
    vector<int> counter(10, 0);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int d = digit(nums[i], exp);
        counter[d]++;
    }
    for (int i = 1; i < 10; i++)
    {
        counter[i] += counter[i - 1];
    }
    vector<int> res(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int d = digit(nums[i], exp);
        int j = counter[d] - 1;
        res[j] = nums[i];
        counter[d]--;
    }
    for (int i = 0; i < n; i++)
        nums[i] = res[i];
}
void Sort(vector<int> &nums)
{
    int m = *max_element(nums.begin(), nums.end());
    for (int exp = 1; exp <= m; exp *= 10)
        countingSortDigit(nums, exp);
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