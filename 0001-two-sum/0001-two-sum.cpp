class Solution {
public:
  /*  // T.C -> O(NlogN), S.C -> O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int left = 0; int right = n - 1;
        
        while(left < right){
            
            int sum = nums[left] + nums[right];
            
            if(sum < target) left++;
            
            else if(sum > target) right--;
            
            else{
                
                return {left,right};
            }
        }
        
        return {};
    }
    */
    
    // T.C -> O(N), S.C -> O(N)
    vector<int> twoSum(vector<int>& nums, int target){
        
        int n = nums.size();
        
        unordered_map<int,int>mp;
        
        for(int i = 0; i < n; i++){
            
            int x = target - nums[i];
            
            if(mp.count(x)){
                
                return {i, mp[x]};
            }
            
            mp[nums[i]] = i;
        }
        
        return {};
    }
};