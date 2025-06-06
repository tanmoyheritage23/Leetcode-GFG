class Solution {
    public int change(int amount, int[] coins) {
       int n = coins.length;
       int[][] dp = new int[n][amount+1];
       for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
       return coinChange(coins,n-1,amount,dp); 
    }
    public int coinChange(int[] coins, int index, int amount, int[][] dp)
    {
        if(index == 0){
            if(amount % coins[0] == 0) return 1;
            else return 0;
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int notTake = coinChange(coins, index - 1, amount,dp);
        int take = 0;
        if(amount >= coins[index]) take += coinChange(coins, index, amount-coins[index],dp); 

        return dp[index][amount] = take + notTake;
        
    }
}