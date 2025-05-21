//[0,1)∏°µ„ ˝≈≈–Ú
#include <bits/stdc++.h>
using namespace std;
void Sort(vector<float> &nums)
{
    int k = nums.size() / 2;
    vector<vector<float>> buckets(k);
    for (float num : nums)
    {
        int i = num * k;
        buckets[i].push_back(num);
    }
    for (vector<float> &bucket : buckets)
        sort(bucket.begin(), bucket.end());
    int i = 0;
    for (vector<float> &bucket : buckets)
        for (float num : bucket)
            nums[i++] = num;
}
int main()
{
    int m;
    cin >> m;
    vector<float> nums(m);
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