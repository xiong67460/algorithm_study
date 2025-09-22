#include <bits/stdc++.h>
using namespace std;

class BinarySearch {
public:
    // 相等返回
    int search(const vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int c = l + (r - l) / 2;
            if (nums[c] == target)
                return c;
            else if (nums[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return -1;
    }

    // 大于等于
    int search1(const vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int c = l + (r - l) / 2;
            if (nums[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return r != nums.size() ? r : -1;
    }

    // 大于
    int search2(const vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int c = l + (r - l) / 2;
            if (nums[c] <= target)
                l = c + 1;
            else
                r = c;
        }
        return r == nums.size() ? -1 : r;
    }

    // 小于等于a（精确匹配）
    int search3a(const vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int c = l + (r - l) / 2;
            if (nums[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return (r == nums.size() || nums[r] != target) ? r - 1 : r;
    }

    // 小于等于b（通用）
    int search3b(const vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int c = l + (r - l) / 2;
            if (nums[c] <= target)
                l = c + 1;
            else
                r = c;
        }
        return r > 0 ? r - 1 : -1;
    }

    // 小于
    int search4(const vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int c = l + (r - l) / 2;
            if (nums[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return r - 1;
    }
};

int main() {
    BinarySearch bs;

    vector<int> nums = {1, 3, 3, 5, 7, 9, 9, 11};
    int target = 9;

    cout << "=== 测试数组: [1, 3, 3, 5, 7, 9, 9, 11], target = " << target << " ===\n";
    cout << "search (== target): " << bs.search(nums, target) << endl;
    cout << "search1 (>= target): " << bs.search1(nums, target) << endl;
    cout << "search2 (> target): " << bs.search2(nums, target) << endl;
    cout << "search3a (<= target): " << bs.search3a(nums, target) << endl;
    cout << "search3b (<= target): " << bs.search3b(nums, target) << endl;
    cout << "search4 (< target): " << bs.search4(nums, target) << endl;

    vector<int> nums2 = {1, 2, 4, 6, 8};
    int target2 = 5;

    cout << "\n=== 测试数组: [1, 2, 4, 6, 8], target = " << target2 << " ===\n";
    cout << "search (== target): " << bs.search(nums2, target2) << endl;
    cout << "search1 (>= target): " << bs.search1(nums2, target2) << endl;
    cout << "search2 (> target): " << bs.search2(nums2, target2) << endl;
    cout << "search3a (<= target): " << bs.search3a(nums2, target2) << endl;
    cout << "search3b (<= target): " << bs.search3b(nums2, target2) << endl;
    cout << "search4 (< target): " << bs.search4(nums2, target2) << endl;

    return 0;
}
