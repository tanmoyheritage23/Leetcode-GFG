class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int left = 0, right = n-1;
        int maxi = 0;
        while(left < right){
            int base = right - left;
            int minHeight = Math.min(height[left],height[right]);
            int area = base * minHeight;
            maxi = Math.max(maxi,area);

            if(height[left] > height[right]) right--;
            else left++;
        }

        return maxi;

    }
}