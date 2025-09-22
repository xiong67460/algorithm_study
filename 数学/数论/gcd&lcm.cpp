#include <bits/stdc++.h>
using namespace std;
// 欧几里得(递归版)
inline int Gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 欧几里得(非递归版)
inline int Gcd2(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 欧几里得(位运算)
inline int Gcd3(int a, int b)
{
    while (b ^= a ^= b ^= a %= b);
    return a;
}

// 更相减损法
int Gcd_b(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

inline int Lcm(int a, int b)
{
    return a / Gcd(a, b) * b;
}