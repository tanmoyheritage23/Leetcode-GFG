class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       int n = nums.size();
       unordered_map<int,int>mp; //counting the oddcount(how many times i have seen the oddcount in past)
        int result = 0, oddCount = 0;
        mp[oddCount] = 1; // i have seen oddCount = 0 once
        
        for(int i = 0; i < n; i++){
            oddCount += (nums[i]%2);
            
            if(mp.count(oddCount - k) > 0){ 
               result += mp[oddCount - k]; 
            }
            
            mp[oddCount]++;
        }
        
        return result;
    }
};