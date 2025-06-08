#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int sum[N], a[N];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <=n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int m;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l-1] << '\n';
    }
    return 0;
}