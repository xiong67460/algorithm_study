#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    int a[250] = {0};
    int b[250] = {0};
    int c[500] = {0};
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
        a[i] = s1[s1.size() - i - 1] - '0';
    for (int i = 0; i < s2.size(); i++)
        b[i] = s2[s2.size() - i - 1] - '0';
    for (int i = 0; i < s2.size(); i++)
        for (int j = 0; j < s1.size(); j++)
        {
            c[i + j] += a[j] * b[i];
            if (c[i + j] >= 10)
            {
                c[i + j + 1]+= c[i + j] / 10;
                c[i + j] %= 10;
            }
        }
    int index = 0;
    for (int i = s1.size() + s2.size(); i >= 0; i--)
        if (c[i] != 0)
        {
            index = i;
            break;
        }
    for (int i = index; i >= 0; i--)
        cout << c[i];
    return 0;
}