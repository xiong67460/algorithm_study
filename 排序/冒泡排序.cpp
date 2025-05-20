#include<bits/stdc++.h>
using namespace std;
void Sort(vector<int> &nums){
    int n = nums.size();
    for (int i = n - 1; i > 0;i--){
        for (int j = 0; j < i;j++){
            if(nums[j]>nums[j+1])
                swap(nums[j], nums[j + 1]);
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