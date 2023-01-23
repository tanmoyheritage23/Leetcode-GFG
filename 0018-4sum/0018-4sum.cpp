class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        vector<vector<int>>res;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < n - 3; i++){
            
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            
            for(int j = i + 1; j < n - 2; j++){
                
                if(j != i + 1 && nums[j] == nums[j - 1]) continue;
               
                int left = j + 1; int right = n - 1;
                
                while(left < right){
                    
                   long int sum = (long int) nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if(sum < target) left++;
                    
                    else if(sum > target) right--;
                    
                    else {
                        
                        vector<int>ans;
                        
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[left]);
                        ans.push_back(nums[right]);
                        
                        res.push_back(ans);
                        
                        left++; right--;
                        
                        while(left < right && nums[left] == nums[left - 1]) left++;
                        while(left < right && nums[right] == nums[right + 1]) right--;
                        
                    }
                }
            }
            
        }
        
        return res;
    }
};