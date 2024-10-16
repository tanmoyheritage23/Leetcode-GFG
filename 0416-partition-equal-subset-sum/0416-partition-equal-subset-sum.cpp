class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) sum += num;
        if(sum%2==1) return false;
        vector<vector<int>>dp(nums.size()+1,vector<int>(sum/2+1,0));
        for(int index = 1; index <= nums.size(); index++){
            for(int subsetSum = 0; subsetSum <= sum/2; subsetSum++){
                if(subsetSum == 0){
                    dp[index][subsetSum] = 1;
                }else{
                    int skip = dp[index-1][subsetSum];
                    int take = 0;
                    if(subsetSum >= nums[index-1]) take = dp[index-1][subsetSum-nums[index-1]];
                    dp[index][subsetSum] = skip | take;
                }
            }
        }
        
        return dp[nums.size()][sum/2];
    }
};