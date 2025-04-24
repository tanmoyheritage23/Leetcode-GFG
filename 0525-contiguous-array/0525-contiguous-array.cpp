class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // We will only store the first occurence of any sum value in the map.
        // For an example if sum = -1 occurs twice we will only store the first
        // occurence. We need difference between First occurence of any sum
        // value(e.g: -1) and last occurence of any sum value to calculate subarray length.
        unordered_map<int, int> mp;
        int ans = 0;
        int maxi = 0;
        int sum = 0;
        mp[sum] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (mp.find(sum) != mp.end()) {
                ans = i - mp[sum];
                maxi = max(maxi, ans);
            } else
                mp[sum] = i;
        }

        return maxi;
    }
};