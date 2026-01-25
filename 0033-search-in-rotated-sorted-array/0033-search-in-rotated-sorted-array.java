class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int ans = -1;

        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] == target)
                ans = mid;

            if (nums[mid] >= nums[0]) // We are in the first increasing sequence
            {
                if (nums[mid] < target || nums[0] > target)
                    l = mid + 1;
                else
                    r = mid - 1;
            } else // We are in the second increasing sequence
            {
                if (nums[mid] > target || nums[n - 1] < target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }

        return ans;
    }
}