#include <bits/stdc++.h>
using namespace std;
void backtrack(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(state);
        return;
    }
    for (int i = start; i < choices.size(); i++)
    {
        if (target - choices[i] < 0)
            break;
        state.push_back(choices[i]);
        backtrack(state, target - choices[i], choices, i, res);
        state.pop_back();
    }
}
vector<vector<int>> subsetSumI(vector<int> &nums, int target)
{
    vector<int> state;
    int start = 0;
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    backtrack(state, target, nums, start, res);
    return res;
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> target;
    vector<vector<int>> res = subsetSumI(nums, target);
    for (const auto &comb : res)
    {
        for (int num : comb)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
