class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int left = 0, right = n-1;
        int leftmax = 0, rightmax = 0;
        int trappedWater = 0;

        while(left < right){
            if(height[left] > height[right]){
                if(height[right] > rightmax){
                    rightmax = height[right];
                }else{
                    trappedWater += rightmax - height[right];
                }
                right--;
            }else{
                if(height[left] > leftmax){
                    leftmax = height[left];
                }else{
                    trappedWater += leftmax - height[left];
                }
                left++;
            }
        }

        return trappedWater;
    }
}