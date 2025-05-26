class Solution {
    public int deleteAndEarn(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        // Extract and sort unique numbers
        List<Integer> unique = new ArrayList<>(count.keySet());
        Collections.sort(unique);

        int n = unique.size();
        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            int val = unique.get(i);
            int earn = val * count.get(val);

            if (i == 0) {
                dp[i] = earn;
            } else if (val == unique.get(i - 1) + 1) {
                dp[i] = Math.max(dp[i - 1], (i >= 2 ? dp[i - 2] : 0) + earn);
            } else {
                dp[i] = dp[i - 1] + earn;
            }
        }

        return dp[n - 1];
    }
}