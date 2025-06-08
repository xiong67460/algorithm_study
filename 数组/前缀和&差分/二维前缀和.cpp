#include <iostream>
using namespace std;
const int N = 1010;
int a[N][N], s[N][N];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m ;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    cin >> k;
    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}
