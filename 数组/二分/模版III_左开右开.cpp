#include <bits/stdc++.h>
using namespace std;

class BinarySearch {
public:
    // 相等返回
    int search(const vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int c = l + (r - l) / 2;
            if (nums[c] == target)
                return c;
            else if (nums[c] < target)
                l = c;
            else
                r = c;
        }
        return -1;
    }

    // 大于等于
    int search1(const vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int c = l + (r - l) / 2;
            if (nums[c] < target)
                l = c;
            else
                r = c;
        }
        return r == nums.size() ? -1 : r;
    }

    // 大于
    int search2(const vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int c = l + (r - l) / 2;
            if (nums[c] <= target)
                l = c;
            else
                r = c;
        }
        return r == nums.size() ? -1 : r;
    }

    // 小于等于
    int search3(const vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int c = l + (r - l) / 2;
            if (nums[c] <= target)
                l = c;
            else
                r = c;
        }
        return l;
    }

    // 小于
    int search4(const vector<int>& nums, int target) {
        int l = -1, r = nums.size();
        while (l + 1 < r) {
            int c = l + (r - l) / 2;
            if (nums[c] < target)
                l = c;
            else
                r = c;
        }
        return l;
    }
};

int main()
{
    BinarySearch bs;
    vector<int> nums = {1, 3, 5, 7, 9};

    cout << "== search ==" << endl;
    cout << "search(nums, 5) => " << bs.search(nums, 5) << endl;

    cout << "== search1 (>=) ==" << endl;
    cout << "search1(nums, 6) => " << bs.search1(nums, 6) << endl;
    cout << "search1(nums, 10) => " << bs.search1(nums, 10) << endl;

    cout << "== search2 (>) ==" << endl;
    cout << "search2(nums, 5) => " << bs.search2(nums, 5) << endl;
    cout << "search2(nums, 9) => " << bs.search2(nums, 9) << endl;

    cout << "== search3 (<=) ==" << endl;
    cout << "search3(nums, 6) => " << bs.search3(nums, 6) << endl;
    cout << "search3(nums, 0) => " << bs.search3(nums, 0) << endl;

    cout << "== search4 (<) ==" << endl;
    cout << "search4(nums, 3) => " << bs.search4(nums, 3) << endl;
    cout << "search4(nums, 1) => " << bs.search4(nums, 1) << endl;

    return 0;
}
