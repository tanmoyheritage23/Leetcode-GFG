class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int n = nums.size();
        int st = 0, end = 0;
        int count = 0, oddCount = 0, result = 0;
        
        for(int end = 0; end < n; end++){
            if(nums[end] % 2 == 1){
                oddCount++;
                count = 0;
            }
            
            while(oddCount == k){
                count++;
                if(st < n && nums[st] % 2 == 1) oddCount--;
                st++;
            }
            
            result += count;
        }
        
        return result;
    }
};