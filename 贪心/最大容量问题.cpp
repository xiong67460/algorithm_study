#include <bits/stdc++.h>
using namespace std;
int maxCapacity(vector<int> &ht)
{
    int i = 0, j = ht.size() - 1;
    int res = 0;
    while (i < j)
    {
        int cap = min(ht[i], ht[j]) * (j - i);
        res = max(res, cap);
        if (ht[i] <= ht[j])
            i++;
        else
            j--;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ht(n);
    for (int i = 0; i < n; i++)
        cin >> ht[i];
    int res = maxCapacity(ht);
    cout << res << '\n';
}