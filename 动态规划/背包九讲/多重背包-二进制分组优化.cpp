#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int dp[N];
int v[N], c[N], s[N];
struct Good
{
    int v, c;
};
vector<Good> process(int n, int *v, int *c, int *s)
{
    vector<Good> goods;
    for (int i = 0; i < n; i++)
    {
        for (int k = 1; k <= s[i]; k *= 2)
        {
            s[i] -= k;
            goods.push_back({k * v[i], k * c[i]});
        }
        if (s[i] > 0)
            goods.push_back({s[i] * v[i], s[i] * c[i]});
    }
    return goods;
}
int solve(int n, int m, vector<Good> goods)
{
    for (auto good : goods)
        for (int j = m; j >= good.c; j--)
            dp[j] = max(dp[j], dp[j - good.c] + good.v);
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
    vector<Good> goods = process(n,v,c,s);
    memset(dp, 0, sizeof(dp));
    cout << solve(n, m, goods) << endl;
}