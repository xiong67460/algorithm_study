#include <bits/stdc++.h>
using namespace std;
struct Pair
{
    int key;
    string val;
    Pair(int key, string val)
    {
        this->key = key;
        this->val = val;
    }
};
class HashMapOpenAddressing
{
private:
    int size;
    int capacity;
    const double loadThres = 2.0 / 3.0;
    const int extendRatio = 2;
    vector<Pair *> buckets;
    Pair *TOMBSTONE = new Pair(-1, "-1");

public:
    HashMapOpenAddressing() : size(0), buckets(capacity, nullptr)
    {
    }
    ~HashMapOpenAddressing()
    {
        for (Pair *pair : buckets)
        {
            if (pair != nullptr && pair != TOMBSTONE)
            {
                delete pair;
            }
        }
        delete TOMBSTONE;
    }
    int hashFunc(int key){
        return key % capacity;
    }
    double loadFactor(){
        return size % capacity;
    }
    
};