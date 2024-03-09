class Solution
{
    
    public:
        int getCommon(vector<int> &nums1, vector<int> &nums2)
        {
            for (int it: nums2)
            {
                if (search(nums1, it))
                {
                    return it;
                }
            }
            return -1;
        }
    
    private:
        bool search(vector<int> &nums1, int x)
        {
            int n = nums1.size();
            int low = 0;
            int high = n - 1;

            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if(nums1[mid] < x) low = mid + 1;
                else if (nums1[mid] > x) high = mid - 1;
                else return true;
            }

            return false;
        }
};