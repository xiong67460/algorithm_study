#include <bits/stdc++.h>
using namespace std;
const int N = 20010;
int v[N], c[N], s[N];
int dp[N], g[N], q[N];
int solve(int n, int m, int *v, int *c, int *s)
{
    return dp[m];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    memset(dp, 0, sizeof(dp));
    cout << solve(n, m, v, c, s) << endl;
}