#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int v[N], c[N];
int dp[N][N];
int solve(int n, int m)
{
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (c[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - c[i]] + v[i]);
    return dp[n][m];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    memset(dp, 0, sizeof(dp));
    cout << solve(n, m) << endl;
    return 0;
}