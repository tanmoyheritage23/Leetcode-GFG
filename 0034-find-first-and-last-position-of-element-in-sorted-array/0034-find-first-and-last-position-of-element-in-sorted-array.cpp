class Solution
{
    public:
        vector<int> searchRange(vector<int> &nums, int target)
        {
            int startingPosition = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            int endingPosition = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

            if (startingPosition > endingPosition - 1) return { -1,
                -1 };

            return {
                startingPosition,
                endingPosition - 1
            };
        }
};