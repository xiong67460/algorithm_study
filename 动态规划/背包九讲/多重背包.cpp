#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int v[N], c[N],s[N];
int dp[N][N];
//化为01背包问题
int solve(int n,int m){
    for (int i = 1; i <= n; i++)                             
        for (int j = 0; j <= m; j++)                         
            for (int k = 0; k <= s[i] && k * c[i] <= j; k++) 
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * c[i]] + k * v[i]);
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
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    memset(dp, 0, sizeof(dp));
    cout << solve(n, m) << endl;
    return 0;
}