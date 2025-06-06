//https://leetcode.cn/discuss/post/3565798/shen-du-pou-xi-er-fen-cha-zhao-by-yukiya-7r19/#c
class BinarySearch {
	// 相等返回
	public int search(int[] nums, int target) {
		int l = 0, r = nums.length - 1;
		while (l <= r) {
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
	public int search1(int[] nums, int target) {
		int l = 0, r = nums.length - 1;
		while (l <= r) {
			int c = l + (r - l) / 2;
			if (nums[c] < target)
				l = c + 1;
			else
				r = c - 1;
		}

		return l == nums.length ? -1 : l;
	}

	// 大于
	public int search2(int[] nums, int target) {
		int l = 0, r = nums.length - 1;
		while (l <= r) {
			int c = l + (r - l) / 2;
			if (nums[c] <= target)
				l = c + 1;
			else
				r = c - 1;
		}
		return l == nums.length ? -1 : l;
	}

	// 小于等于
	public int search3(int[] nums, int target) {
		int l = 0, r = nums.length - 1;
		while (l <= r) {
			int c = l + (r - l) / 2;
			if (nums[c] <= target)
				l = c + 1;
			else
				r = c - 1;
		}
		return r;
	}

	// 小于
	public int search4(int[] nums, int target) {
		int l = 0, r = nums.length - 1;
		while (l <= r) {
			int c = l + (r - l) / 2;
			if (nums[c] < target)
				l = c + 1;
			else
				r = c - 1;
		}
		return r;
	}
}

public class 模版I_左闭右闭 {
	public static void main(String[] args) {
		BinarySearch binarySearch = new BinarySearch();

		int[] nums = { 1, 3, 5, 7, 9, 11, 13 };
		int target = 7;
		System.out.println("search: " + binarySearch.search(nums, target));

		target = 8;
		System.out.println("search1 (>= 8): " + binarySearch.search1(nums, target));
		System.out.println("search2 (> 8): " + binarySearch.search2(nums, target));
		System.out.println("search3 (<= 8): " + binarySearch.search3(nums, target));
		System.out.println("search4 (< 8): " + binarySearch.search4(nums, target));
	}
}
