#include <bits/stdc++.h>
using namespace std;

const int MAX = 200010;
int f[MAX];

int main()
{
    int n, m;
    cin >> n >> m;
    fill(f, f + MAX, -1); 
    queue<int> q;
    q.push(n);
    f[n] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == m)
            break;
        int nexts[3] = {cur - 1, cur + 1, cur * 2};
        for (int i = 0; i < 3; ++i)
        {
            int nxt = nexts[i];
            if (nxt >= 0 && nxt < MAX && f[nxt] == -1)
            {
                f[nxt] = f[cur] + 1;
                q.push(nxt);
            }
        }
    }
    cout << f[m] << endl;
}
