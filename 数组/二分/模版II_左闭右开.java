class BinarySearch {
    // 相等返回
    public int search(int[] nums, int target) {
        int l = 0, r = nums.length;
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
    public int search1(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int c = l + (r - l) / 2;
            if (nums[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return r != nums.length ? r : -1;
    }

    // 大于
    public int search2(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int c = l + (r - l) / 2;
            if (nums[c] <= target)
                l = c + 1;
            else
                r = c;
        }
        return r == nums.length ? -1 : r;
    }

    // 小于等于a
    public int search3a(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int c = l + (r - l) / 2;
            if (nums[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return (r == nums.length || nums[r] != target) ? r - 1 : r;
    }

    // 小于等于b
    public int search3b(int[] nums, int target) {
        int l = 0, r = nums.length;
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
    public int search4(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int c = l + (r - l) / 2;
            if (nums[c] < target)
                l = c + 1;
            else
                r = c;
        }
        return r - 1;
    }
}

public class 模版II_左闭右开 {
    public static void main(String[] args) {
        BinarySearch bs = new BinarySearch();
        int[] nums = { 1, 3, 3, 5, 7, 9, 9, 11 };
        int target = 9;

        System.out.println("=== 测试数组: [1, 3, 3, 5, 7, 9, 9, 11], target = " + target + " ===");

        System.out.println("search (== target): " + bs.search(nums, target));
        System.out.println("search1 (>= target): " + bs.search1(nums, target));
        System.out.println("search2 (> target): " + bs.search2(nums, target));
        System.out.println("search3a (<= target): " + bs.search3a(nums, target));
        System.out.println("search3b (<= target): " + bs.search3b(nums, target));
        System.out.println("search4 (< target): " + bs.search4(nums, target));

        int[] nums2 = { 1, 2, 4, 6, 8 };
        int target2 = 5;

        System.out.println("\n=== 测试数组: [1, 2, 4, 6, 8], target = " + target2 + " ===");
        System.out.println("search (== target): " + bs.search(nums2, target2));
        System.out.println("search1 (>= target): " + bs.search1(nums2, target2));
        System.out.println("search2 (> target): " + bs.search2(nums2, target2));
        System.out.println("search3a (<= target): " + bs.search3a(nums2, target2));
        System.out.println("search3b (<= target): " + bs.search3b(nums2, target2));
        System.out.println("search4 (< target): " + bs.search4(nums2, target2));
    }
}
