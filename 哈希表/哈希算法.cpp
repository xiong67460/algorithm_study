#include <bits/stdc++.h>
using namespace std;
/*¼Ó·¨¹þÏ£*/
int addHash(string key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash = (hash + (int)c) % MODULUS;
    }
    return (int)hash;
}

/*³Ë·¨¹þÏ£*/
int mulHash(string key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash = (31 * hash + (int)c) % MODULUS;
    }
    return (int)hash;
}

/*Òì»ò¹þÏ£*/
int xorHash(string key)
{
    int hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash ^= (int)c;
    }
    return hash & MODULUS;
}

/*Ðý×ª¹þÏ£*/
int rotHash(string key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash = ((hash << 4) ^ (hash >> 28) ^ (int)c) % MODULUS;
    }
    return (int)hash;
}
