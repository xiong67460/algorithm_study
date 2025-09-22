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
class HashMapChaining
{
private:
    int size;
    int capacity;
    double loadThres;
    int extendRatio;
    vector<vector<Pair *>> buckets;

public:
    HashMapChaining() : size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2) { buckets.resize(capacity); }
    ~HashMapChaining()
    {
        for (auto &bucket : buckets)
        {
            for (Pair *pair : bucket)
            {
                delete pair;
            }
        }
    }
    int hashFunc(int key)
    {
        return key % capacity;
    }
    double loadFactor()
    {
        return (double)size / (double)capacity;
    }
    string get(int key)
    {
        int index = hashFunc(key);
        for (Pair *pair : buckets[index])
        {
            if (pair->key == key)
            {
                return pair->val;
            }
        }
        return "";
    }
    void extend()
    {
        vector<vector<Pair *>> bucketsTmp = buckets;
        capacity *= extendRatio;
        buckets.clear();
        buckets.resize(capacity);
        size = 0;
        for (auto &bucket : bucketsTmp)
        {
            for (Pair *pair : bucket)
            {
                put(pair->key, pair->val);
                delete pair;
            }
        }
    }
    void put(int key, string val)
    {
        if (loadFactor() > loadThres)
        {
            extend();
        }
        int index = hashFunc(key);
        for (Pair *pair : buckets[index])
        {
            if (pair->key == key)
            {
                pair->val = val;
                return;
            }
        }
        buckets[index].push_back(new Pair(key, val));
        size++;
    }
    void remove(int key)
    {
        int index = hashFunc(key);
        auto &bucket = buckets[index];
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i]->key == key)
            {
                Pair *tmp = bucket[i];
                bucket.erase(bucket.begin() + i);
                size--;
                return;
            }
        }
    }
    void print()
    {
        for (auto &bucket : buckets)
        {
            cout << "[";
            for (Pair *pair : bucket)
            {
                cout << pair->key << " -> " << pair->val << ", ";
            }
            cout << "]\n";
        }
    }
};
int main()
{
    HashMapChaining map;
    map.put(1, "apple");
    map.put(2, "banana");
    map.put(3, "cherry");
    map.put(4, "date");
    cout << "Initial map:\n";
    map.print();
    cout << "\nGet key 2: " << map.get(2) << "\n";
    map.put(2, "blueberry");
    cout << "\nAfter updating key 2:\n";
    map.print();
    map.remove(3);
    cout << "\nAfter removing key 3:\n";
    map.print();
    return 0;
}
