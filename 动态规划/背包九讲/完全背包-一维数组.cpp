#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int v[N], c[N];
int dp[N];
int solve(int n, int m){
    for (int i = 1; i <= n;i++)
        for (int j = c[i]; j <= m;j++)
            dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
    return dp[m];
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