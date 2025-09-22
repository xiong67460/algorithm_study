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
class ArrayHashMap
{
private:
    vector<Pair *> buckets;

public:
    ArrayHashMap()
    {
        buckets = vector<Pair *>(100);
    }
    ~ArrayHashMap()
    {
        for (const auto &bucket : buckets)
            delete bucket;
        buckets.clear();
    }
    int hashFunc(int key)
    {
        int index = key % 100;
        return index;
    }
    string get(int key)
    {
        int index = hashFunc(key);
        Pair *pair = buckets[index];
        if (pair == nullptr)
            return "";
        return pair->val;
    }
    void put(int key, string val)
    {
        Pair *pair = new Pair(key, val);
        int index = hashFunc(key);
        buckets[index] = pair;
    }
    void remove(int key)
    {
        int index = hashFunc(key);
        delete buckets[index];
        buckets[index] = nullptr;
    }
    vector<Pair *> pairSet()
    {
        vector<Pair *> pairSet;
        for (Pair *pair : buckets)
        {
            if (pair != nullptr)
                pairSet.push_back(pair);
        }
        return pairSet;
    }
    vector<int> keySet()
    {
        vector<int> keySet;
        for (Pair *pair : buckets)
        {
            if (pair != nullptr)
                keySet.push_back(pair->key);
        }
        return keySet;
    }
    vector<string> valSet()
    {
        vector<string> valSet;
        for (Pair *pair : buckets)
        {
            if (pair != nullptr)
                valSet.push_back(pair->val);
        }
        return valSet;
    }
    void print()
    {
        for (Pair *kv : pairSet())
        {
            cout << kv->key << " -> " << kv->val << endl;
        }
    }
};
int main()
{
    ArrayHashMap map;
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
