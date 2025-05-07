#include <iostream>
#include <vector>
using namespace std;
int horse_moves[8][2] = {
    {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
int solve(int n, int m, int horse_x, int horse_y)
{
    vector<vector<bool>> blocked(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < 8; i++)
    {
        int dx = horse_x + horse_moves[i][0];
        int dy = horse_y + horse_moves[i][1];
        if (dx >= 0 && dx <= n && dy >= 0 && dy <= m)
        {
            blocked[dx][dy] = true;
        }
    }
    if (horse_x >= 0 && horse_x <= n && horse_y >= 0 && horse_y <= m)
    {
        blocked[horse_x][horse_y] = true;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    if (blocked[0][0])
    {
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (blocked[i][j])
            {
                dp[i][j] = 0;
            }
            else
            {
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
    }
    return dp[n][m];
}

int main()
{
    int n, m, horse_x, horse_y;
    cin >> n >> m >> horse_x >> horse_y;
    cout << solve(n, m, horse_x, horse_y) << endl;
    return 0;
}
