#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int v[N],w[N];
int dp[N][N];
int main(){
    int n,V;
    cin >> n>>V;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n;i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= V;j++){
            if(v[i]>j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << dp[n][V];
    return 0;
}
