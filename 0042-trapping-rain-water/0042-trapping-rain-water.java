class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int left = 0; int right = n - 1;
        int leftMax = -1; int rightMax = height[right];
        int trappedWater = 0;

        while(left <= right) {
            if(leftMax > rightMax) {
                if(height[right] > rightMax) rightMax = height[right];
                else trappedWater += rightMax - height[right];
                right--;

            }else {
                if(height[left] > leftMax) leftMax = height[left];
                else trappedWater += leftMax - height[left];
                left++;
            }
        }
        return trappedWater;
    }
}