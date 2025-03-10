class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxi = 0;
        while(left < right){
            int base = right - left;
            int minHeight = min(height[left],height[right]);
            int area = base * minHeight;
            maxi = max(maxi,area);

            if(height[left] > height[right]) right--;
            else left++;
        }

        return maxi;
    }
};