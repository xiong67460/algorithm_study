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
        if (i > start && choices[i] == choices[i - 1])
            continue;
        ;
        state.push_back(choices[i]);
        backtrack(state, target - choices[i], choices, i + 1, res);
        state.pop_back();
    }
}
vector<vector<int>> subsetSumII(vector<int> &nums, int target)
{
    vector<int> state;
    vector<vector<int>> res;
    int start = 0;
    sort(nums.begin(), nums.end());
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
    vector<vector<int>> res = subsetSumII(nums, target);
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