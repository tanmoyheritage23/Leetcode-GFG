class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int st = 0, end = 0, maxi = 0;
        
        while(end<n){
           if(nums[end]==0) k--;
            
            while(k<0){
                if(nums[st]==0) k++;
                st++;
            }
            
            maxi = Math.max(maxi,end-st+1);
             end++;   
        }
        
        return maxi;
    }
}