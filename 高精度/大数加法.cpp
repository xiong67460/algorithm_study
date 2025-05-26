#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    int a1[210] = {0}, a2[210] = {0}, a3[210] = {0};
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
        a1[s1.size() - i - 1] = s1[i] - '0';
    for (int i = 0; i < s2.size(); i++)
        a2[s2.size() - i - 1] = s2[i] - '0';
    int len = max(s1.size(), s2.size());
    for (int i = 0; i < len; i++)
    {
        a3[i] += a2[i] + a1[i];
        if (a3[i] >= 10)
        {
            a3[i + 1] += 1;
            a3[i] %= 10;
        }
    }
    if (a3[len] != 0)
        len++;
    int index = 0;
    for (int i = len; i >= 0; i--)
        if (a3[i] != 0)
        {
            index = i;
            break;
        }
    for (int i = index; i >= 0; i--)
        cout << a3[i];
    return 0;
}