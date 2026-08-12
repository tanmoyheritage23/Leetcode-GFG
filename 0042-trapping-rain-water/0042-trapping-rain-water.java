class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int count = 0, left = 0, right = n - 1;
        int leftMax = height[left];
        int rightMax = height[right];

        while(left <= right){
            if(leftMax < rightMax){
                if(leftMax > height[left]){
                    count += leftMax - height[left];
                }else{
                    leftMax = height[left];
                }
                left++;
            } else{
                if(rightMax > height[right]){
                    count += rightMax - height[right];
                }else{
                    rightMax = height[right];
                }
                right--;
            }
        }
        return count;
    }
}