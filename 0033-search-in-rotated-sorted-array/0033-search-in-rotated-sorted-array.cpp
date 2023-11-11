class Solution
{
    public:
        int search(vector<int> &nums, int target)
        {
           	// at any point either the right half will be sorted or the left half will be sorted. now if the left half is sorted then check wheather the target is in left half or not. if it is in left half then eliminate the right half else eliminate the left half. If the right half is sorted then do the same thing
            int low = 0;
            int high = nums.size() - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (nums[mid] == target) return mid;
               	// left half is sorted
                else if (nums[mid] >= nums[low])
                {
                    if (nums[low] <= target && nums[mid] >= target)
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
               	// right half is sorted
                else
                {
                    if (nums[mid] <= target && nums[high] >= target)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }

            return -1;
        }
};