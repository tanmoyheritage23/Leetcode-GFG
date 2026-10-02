class Solution {
    public int maxSubarray(int[] nums) {
        int n = nums.length;
        int[] freq = new int[501];
        
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            int x = nums[right];

            // If x cannot be safely added to the current window [left..right-1],
            // shrink the window from the left until x becomes valid.
            while (!isValid(x, freq)) {
                freq[nums[left]]--;
                left++;
            }

            // Add the current element into the window
            freq[x]++;

            // Update max length
            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    private boolean isValid(int x, int[] freq) {
        // --- CHECK 1: x acts as the sum (a + b = x) ---
        for (int a = 1; a <= x / 2; a++) {
            int b = x - a;
            if (a == b) {
                if (freq[a] >= 2) return false;
            } else {
                if (freq[a] > 0 && freq[b] > 0) return false;
            }
        }

        // --- CHECK 2: x acts as an addend (x + y = sum) ---
        for (int y = 1; y <= 500; y++) {
            if (freq[y] > 0) {
                int sum = x + y;
                if (sum <= 500 && freq[sum] > 0) {
                    return false;
                }
            }
        }

        return true;
    }
}