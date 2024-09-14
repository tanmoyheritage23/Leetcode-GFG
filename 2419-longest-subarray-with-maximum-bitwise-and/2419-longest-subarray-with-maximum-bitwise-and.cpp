class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int maxi = 0; 
        
       
         maxi = *max_element(nums.begin(),nums.end());
        
    
        int cnt = 1; int maximum = 1;
        for(int i = 1; i < n; i++){
            
            if(nums[i] == maxi && nums[i] == nums[i-1]){
                
                cnt++;
                
            }
            
            else{
                
                cnt = 1;
                
            }
            
            maximum = max(maximum,cnt);
        }
        
        return maximum;
    }
};