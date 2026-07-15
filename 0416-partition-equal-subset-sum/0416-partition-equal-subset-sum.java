class Solution {
    private boolean subsetSumEqualToTarget(int n,int k,int[] nums){
        boolean[][] dp = new boolean[n][k+1];
        
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0] <= k) dp[0][nums[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                boolean nottake=dp[ind-1][target];
                boolean take=false;
                if(target>=nums[ind]) take=dp[ind-1][target-nums[ind]];
                dp[ind][target]=take|nottake;
            }
        }
        
        return dp[n-1][k];
    }
    public boolean canPartition(int[] nums) {
        int n=nums.length;
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        if(totalsum%2 == 1) return false;
        
        int k=totalsum/2;
        
        return subsetSumEqualToTarget(n,k,nums);
    }
}