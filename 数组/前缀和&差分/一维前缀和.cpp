#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int sum[N], a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum[i] = i ? sum[i - 1] + a[i] : a[i];
    }
    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << (l?sum[r] - sum[l - 1]:sum[r]) << '\n';
    }
    return 0;
}