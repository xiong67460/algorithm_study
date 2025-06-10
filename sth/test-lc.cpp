#include "../utils/common.hpp"
int solve(vector<vector<int>> &nums, int n)
{   if(n==1)
        return 0;
    int res = INT_MAX;
    for (auto &num : nums)
    {
        if (num[1]==n)
            res = min(res, solve(nums, n - 1));
    }
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 3; j++)
            cin >> nums[i][j];
    cout << solve(nums, m);
}