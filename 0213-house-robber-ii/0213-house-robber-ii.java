class Solution {
    private int maxRobAmount(List<Integer> nums){
        int n = nums.size();
        int[] dp = new int[n];

        dp[0] = nums.get(0);

        for(int i = 1; i < n; i++){
            int pick = nums.get(i);
            if(i > 1) pick += dp[i-2];
            int notPick = dp[i-1];

            dp[i] = Math.max(pick,notPick);
        }

        return dp[n-1];
    }
    public int rob(int[] nums) {
        List<Integer>temp1 = new ArrayList<>();
        List<Integer>temp2 = new ArrayList<>();

        int n = nums.length;

        if(n == 1) return nums[0];

        for(int i = 0; i < n; i++){
            if(i != 0) temp1.add(nums[i]);
            if(i != n-1) temp2.add(nums[i]);
        }

        return Math.max(maxRobAmount(temp1), maxRobAmount(temp2));
    }
}