#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums, int left, int mid, int right)
{
    vector<int> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }
    while(i<=mid)
    {
        tmp[k++] = nums[i++];
    }
    while(j<=right){
        tmp[k++] = nums[j++];
    }
    for (int k = 0; k < tmp.size();k++)
        nums[left + k] = tmp[k];
}
void Sort(vector<int>&nums,int left,int right){
    if(left>=right)
        return;
    int mid = left + (right - left) / 2;
    Sort(nums, left, mid);
    Sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
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
    Sort(nums,0,m-1);
    for (int i = 0; i < m; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}