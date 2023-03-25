class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int n = nums.size();
        int st, ansSt, ansEnd = 0;
        
        for(int i = 0; i < n; i++){
            if(sum == 0) st = i;
            sum += nums[i];
            
            if(sum > maxi) maxi = sum, ansSt = st, ansEnd = i;
            
            if(sum < 0) sum = 0;
        }
        
        return maxi;
    }
};