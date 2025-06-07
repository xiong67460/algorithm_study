#include <bits/stdc++.h>
using namespace std;
// 欧几里得(递归版)
inline int
gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 欧几里得(非递归版)
inline int gcd2(int a, int b)
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
inline int gcd3(int a, int b)
{
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}

//更相减损法
int gcd_b(int a,int b){
    while(a!=b){
        if(a>b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

inline int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}