class Solution
{
    public:
        vector<vector < int>> fourSum(vector<int> &nums, int target)
        {
           	// -2 -1 0 0 1 2 
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<vector < int>> res;
            for (int a = 0; a < n - 3; a++)

            {
                if (a != 0 && nums[a] == nums[a - 1]) continue;
                for (int b = a + 1; b < n - 2; b++)

                {
                    if (b != a + 1 && nums[b] == nums[b - 1]) continue;
                    int c = b + 1, d = n - 1;

                    while (c < d)
                    {
                        long int sum = (long int) nums[a] + nums[b] + nums[c] + nums[d];
                        if (sum == target)
                        {
                            vector<int> vec;
                            vec.push_back(nums[a]);
                            vec.push_back(nums[b]);
                            vec.push_back(nums[c]);
                            vec.push_back(nums[d]);
                            res.push_back(vec);
                            c++, d--;
                            while (c < d && nums[c] == nums[c - 1]) c++;
                            while (c < d && nums[d] == nums[d + 1]) d--;
                        }
                        else if (sum > target) d--;
                        else c++;
                    }
                }
            }

            return res;
        }
};