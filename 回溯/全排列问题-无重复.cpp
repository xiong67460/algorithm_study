#include <bits/stdc++.h>
using namespace std;
void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res)
{
    if (state.size() == choices.size())
    {
        res.push_back(state);
        return;
    }
    for (int i = 0; i < choices.size(); i++)
    {
        int choice = choices[i];
        if (!selected[i])
        {
            selected[i] = true;
            state.push_back(choice);
            backtrack(state, choices, selected, res);
            selected[i] = false;
            state.pop_back();
        }
    }
}
vector<vector<int>> permutationsI(vector<int> nums)
{
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrack(state, nums, selected, res);
    return res;
}
int main()
{
    vector<int> nums = {1, 2, 3, 8, 9};
    vector<vector<int>> res = permutationsI(nums);
    cout << "All permutations of [";
    for (size_t i = 0; i < nums.size(); ++i)
    {
        cout << nums[i];
        if (i < nums.size() - 1)
            cout << ", ";
    }
    cout << "] are:" << endl;
    for (const auto &perm : res)
    {
        for (int num : perm)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}