class Solution
{
    private:
        void findAllSubsets(int ind, vector<int> &subset, vector<vector< int >> &ans, vector< int > &nums)
        {
            if (ind == nums.size())
            {
                ans.push_back(subset);
                return;
            }

           	// picking
            subset.push_back(nums[ind]);
            findAllSubsets(ind + 1, subset, ans, nums);

           	// poping back after recursion is over to explore other opportunites
            subset.pop_back();
            findAllSubsets(ind + 1, subset, ans, nums);
        }
    public:
        vector<vector < int>> subsets(vector<int> &nums)
        {
            vector<vector < int>> ans;
            vector<int> subset;
            findAllSubsets(0, subset, ans, nums);
            return ans;
        }
};