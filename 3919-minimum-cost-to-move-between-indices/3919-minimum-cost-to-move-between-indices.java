class Solution {
    public int[] minCost(int[] nums, int[][] queries) {
        int n = nums.length;

        // closest[i] = closest adjacent index for i

        int[] closest = new int[n];

        for (int i = 0; i < n; i++) {

            // First index

            if (i == 0) {

                closest[i] = 1;

            }

            // Last index

            else if (i == n - 1) {

                closest[i] = n - 2;

            }

            // Middle indices

            else {

                long leftDiff = nums[i] - nums[i - 1];

                long rightDiff = nums[i + 1] - nums[i];

                if (leftDiff <= rightDiff) {

                    closest[i] = i - 1;

                } else {

                    closest[i] = i + 1;

                }

            }

        }

        // forward[i] = min cost from i -> i+1

        long[] forward = new long[n - 1];

        for (int i = 0; i < n - 1; i++) {

            long direct = nums[i + 1] - nums[i];

            long special = (closest[i] == i + 1) ? 1 : Long.MAX_VALUE;

            forward[i] = Math.min(direct, special);

        }

        // backward[i] = min cost from i -> i-1

        long[] backward = new long[n];

        for (int i = 1; i < n; i++) {

            long direct = nums[i] - nums[i - 1];

            long special = (closest[i] == i - 1) ? 1 : Long.MAX_VALUE;

            backward[i] = Math.min(direct, special);

        }

        // Prefix sums for forward -> min cost from 0 to ith index

        long[] prefForward = new long[n];

        for (int i = 1; i < n; i++) {

            prefForward[i] = prefForward[i - 1] + forward[i - 1];

        }

        // Prefix sums for backward -> min cost from ith index to 0

        long[] prefBackward = new long[n];

        for (int i = 1; i < n; i++) {

            prefBackward[i] = prefBackward[i - 1] + backward[i];

        }

        // Answer queries

        int[] ans = new int[queries.length];

        for (int i = 0; i < queries.length; i++) {

            int l = queries[i][0];

            int r = queries[i][1];

            // Moving right

            if (l < r) {

                ans[i] = (int)prefForward[r] - (int)prefForward[l];

            }

            // Moving left

            else {

                ans[i] = (int)prefBackward[l] - (int)prefBackward[r];

            }

        }

        return ans;
    }
}