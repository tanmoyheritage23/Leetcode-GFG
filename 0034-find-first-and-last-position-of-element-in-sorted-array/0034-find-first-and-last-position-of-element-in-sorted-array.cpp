class Solution
{
    public:
        vector<int> searchRange(vector<int> &nums, int target)
        {
            int n = nums.size();
            int firstPosition = -1;
            int lastPosition = -1;
           	// Find starting position 
            int st = 0;
            int end = n - 1;

            while (st <= end)
            {
                int mid = st + (end - st) / 2;
                if (nums[mid] == target) firstPosition = mid, end = mid - 1;
                else if (nums[mid] > target) end = mid - 1;
                else st = mid + 1;
            }

           	// Find last position 
            st = 0;
            end = n - 1;

            while (st <= end)
            {
                int mid = st + (end - st) / 2;
                if (nums[mid] == target) lastPosition = mid, st = mid + 1;
                else if (nums[mid] > target) end = mid - 1;
                else st = mid + 1;
            }

            return {
                firstPosition,
                lastPosition
            };
        }
};