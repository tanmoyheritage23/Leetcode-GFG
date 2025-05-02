class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>>res;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < n - 2; i++){
            
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1; int right = n - 1;
            
            while(left < right){
                
                int sum = nums[i] + nums[left] + nums[right];
                
                if(sum < 0) left++;
                
                else if(sum > 0) right--;
                
                else{
                    
                    vector<int>ans;
                    
                    ans.push_back(nums[i]);
                    ans.push_back(nums[left]);
                    ans.push_back(nums[right]);
                    
                    res.push_back(ans);
                    
                    left++; right--;
                    
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        
        return res;
    }
};