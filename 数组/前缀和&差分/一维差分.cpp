#include <iostream>
using namespace std;
const int N = 100010;
int a[N], s[N];
void insert(int l, int r, int c)
{
    s[l] += c;
    s[r + 1] -= c;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n ;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(i, i, a[i]);
    }
    cin >> m;
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1];
    for (int i = 1; i <= n; i++)
        cout << s[i] << " ";
    return 0;
}

