class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n+1];

        
        
        for(int i = n - 1; i >= 0; i--){
            int len = 0;int localMax = 0;
            int partitionMax = 0;
            int maxSum = 0;
            for(int j = i; j < Math.min(i+k,n); j++){
            len++;
            partitionMax = Math.max(partitionMax,arr[j]);
            localMax = partitionMax * len + dp[j+1];
            maxSum = Math.max(maxSum,localMax);
            }
            dp[i] = maxSum;
            System.out.println(dp[i]);
        }

        return dp[0];

    }
}