class Solution
{
    public:
        long long countSubarrays(vector<int> &nums, int k)
        {
            int n = nums.size();
            int st = 0;
            int end = 0;
            int maxi = 0;
            maxi = *max_element(nums.begin(), nums.end());
            int cnt = 0;
            long long ans = 0;

            while (end < n)
            {
                if (nums[end] == maxi) cnt++;
                if (cnt >= k)
                {
                    while (cnt >= k)
                    {
                        ans += n - end;
                        if (nums[st] == maxi) cnt--;
                        st++;
                    }
                }
                end++;
            }

            return ans;
        }
};