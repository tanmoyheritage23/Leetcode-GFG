class Solution
{
    public:
        int subarraysWithKDistinct(vector<int> &nums, int k)
        {
            return totalSubarraysWithAtmostKDistinct(nums, k) - totalSubarraysWithAtmostKDistinct(nums, k - 1);
        }

    private:
        int totalSubarraysWithAtmostKDistinct(vector<int> &nums, int k)
        {
            int n = nums.size();
            unordered_map<int, int> mp;
            int st = 0;
            int end = 0;
            int res = 0;
            while (end < n)
            {

                mp[nums[end]]++;
                while (mp.size() > k)
                {
                    mp[nums[st]]--;
                    if (mp[nums[st]] == 0) mp.erase(nums[st]);
                    st++;
                }
                res += (end - st + 1);
                end++;
            }
            return res;
        }
};