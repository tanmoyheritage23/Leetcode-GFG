class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int left = 0;
        int right = n - 1;
        int maxContainerLimit = 0;
        while (left < right) {
            int base = right - left;
            int containerLimit = 0;
            if (height[left] > height[right]) {
                containerLimit = base * height[right];
                right--;
            } else {
                containerLimit = base * height[left];
                left++;
            }
            maxContainerLimit = Math.max(maxContainerLimit, containerLimit);
        }
        return maxContainerLimit;
    }
}