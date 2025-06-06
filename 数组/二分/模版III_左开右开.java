class BinarySearch {
    // 相等返回
    public int search(int[] nums, int target) {
        int l = -1, r = nums.length;
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
    public int search1(int[] nums, int target) {
        int l = -1, r = nums.length;
        while (l + 1 < r) {
            int c = l + (r - l) / 2;
            if (nums[c] < target)
                l = c;
            else
                r = c;
        }
        return r == nums.length ? -1 : r;
    }

    // 大于
    public int search2(int[] nums, int target) {
        int l = -1, r = nums.length;
        while (l + 1 < r) {
            int c = l + (r - l) / 2;
            if (nums[c] <= target)
                l = c;
            else
                r = c;
        }
        return r == nums.length ? -1 : r;
    }

    // 小于等于
    public int search3(int[] nums, int target) {
        int l = -1, r = nums.length;
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
    public int search4(int[] nums, int target) {
        int l = -1, r = nums.length;
        while (l + 1 < r) {
            int c = l + (r - l) / 2;
            if (nums[c] < target)
                l = c; 
            else
                r = c; 
        }
        return l;
    }
}

public class 模版III_左开右开 {
    public static void main(String[] args) {
        BinarySearch bs = new BinarySearch();

        int[] nums = { 1, 3, 5, 7, 9 };

        int target = 5;
        System.out.println("== search ==");
        System.out.println("search(nums, 5) => " + bs.search(nums, target));

        System.out.println("== search1 (>=) ==");
        System.out.println("search1(nums, 6) => " + bs.search1(nums, 6));
        System.out.println("search1(nums, 10) => " + bs.search1(nums, 10));

        System.out.println("== search2 (>) ==");
        System.out.println("search2(nums, 5) => " + bs.search2(nums, 5));
        System.out.println("search2(nums, 9) => " + bs.search2(nums, 9));

        System.out.println("== search3 (<=) ==");
        System.out.println("search3(nums, 6) => " + bs.search3(nums, 6));
        System.out.println("search3(nums, 0) => " + bs.search3(nums, 0));

        System.out.println("== search4 (<) ==");
        System.out.println("search4(nums, 3) => " + bs.search4(nums, 3));
        System.out.println("search4(nums, 1) => " + bs.search4(nums, 1));
    }
}
