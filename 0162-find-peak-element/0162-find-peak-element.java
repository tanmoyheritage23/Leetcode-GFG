class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0; // for strictly decreasing array (e.g 5,4,3,2,1) or (e.g 5 4 6 .. something like this)
        if(nums[n-1]>nums[n-2]) return n-1; // for strictly increasing array (e.g 1,2,3,4,5) or something like this (e.g. 10 11 2 3 5)
        
        int low = 1, high = n-2;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]) return mid; //mid is on the peak
            else if(nums[mid]>nums[mid-1]) low = mid+1;// mid is on the increasing line
            else if(nums[mid]>nums[mid+1]) high = mid-1; // mid is on the decreasing line
            else low = mid+1; // mid is on the reverse peak (e.g 1,5,1,2,1) then it does not matter, I discard the right part or left
        
        }
        
        return -1;
    }
}