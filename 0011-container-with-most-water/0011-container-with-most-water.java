class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int left = 0; int right = n - 1;
        int maxWater = 0;

        while(left < right) {
            int h = Math.min(height[left],height[right]);
            int area = (right - left) * h;
            maxWater = Math.max(area,maxWater);

            if(height[right] > height[left]) left++;
            else right--;
        }

        return maxWater;
    }
}