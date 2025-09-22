#include <bits/stdc++.h>
using namespace std;
int  main()
{
    string s;
    int b;
    int a[250] = {0}, c[250] = {0};
    cin >> s >> b;
    for (int i = 0; i < s.size(); i++)
        a[i] = s[i] - '0';
    int t = 0;
    for (int i = 0; i < s.size(); i++)
    {
        t = t * 10 + a[i];
        if (t > b)
        {
            c[i] = t / b;
            t %= b;
        }
    }
    int index = 0;
    for (int i = 0; i < s.size(); i++)
        if (c[i] != 0)
        {
            index = i;
            break;
        }
    for (int i = index; i < s.size();i++)
        cout << c[i];
    cout << '\n'
         << "余为" << t;
    return 0;
}