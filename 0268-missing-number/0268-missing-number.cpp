class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        /* cyclic sort */
        
        int n = nums.size();
        
        int i = 0; 
        
        while(i < n){
            
            int correct = nums[i];
            
            if(nums[i] < n && nums[i] != nums[correct]){ // if n is present in the array i.e. if nums[i] = n then we will skip the swap part.
                
                swap(nums[i],nums[correct]);
            }
            
            else i++;
        }
        
        for(int i = 0; i < n; i++){
            
            if(nums[i] != i) return i;
        }
        
        return n; // when nums is sorted and all the elements are in their actual position where they should be.
    }
};