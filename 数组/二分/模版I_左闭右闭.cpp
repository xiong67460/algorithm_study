#include <bits/stdc++.h>
using namespace std;

class BinarySearch
{
public:
	// 相等返回
	int search(const vector<int> &nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int c = l + (r - l) / 2;
			if (nums[c] == target)
				return c;
			else if (nums[c] < target)
				l = c + 1;
			else
				r = c - 1;
		}
		return -1;
	}

	// 大于等于
	int search1(const vector<int> &nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int c = l + (r - l) / 2;
			if (nums[c] < target)
				l = c + 1;
			else
				r = c - 1;
		}
		return l == nums.size() ? -1 : l;
	}

	// 大于
	int search2(const vector<int> &nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int c = l + (r - l) / 2;
			if (nums[c] <= target)
				l = c + 1;
			else
				r = c - 1;
		}
		return l == nums.size() ? -1 : l;
	}

	// 小于等于
	int search3(const vector<int> &nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int c = l + (r - l) / 2;
			if (nums[c] <= target)
				l = c + 1;
			else
				r = c - 1;
		}
		return r;
	}

	// 小于
	int search4(const vector<int> &nums, int target)
	{
		int l = 0, r = nums.size() - 1;
		while (l <= r)
		{
			int c = l + (r - l) / 2;
			if (nums[c] < target)
				l = c + 1;
			else
				r = c - 1;
		}
		return r;
	}
};

int main()
{
	BinarySearch bs;

	vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
	int target = 7;
	cout << "search: " << bs.search(nums, target) << endl;

	target = 8;
	cout << "search1 (>= 8): " << bs.search1(nums, target) << endl;
	cout << "search2 (> 8): " << bs.search2(nums, target) << endl;
	cout << "search3 (<= 8): " << bs.search3(nums, target) << endl;
	cout << "search4 (< 8): " << bs.search4(nums, target) << endl;

	return 0;
}
