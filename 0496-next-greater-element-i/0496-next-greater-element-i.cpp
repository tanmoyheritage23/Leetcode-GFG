class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {
            unordered_map<int, int> mp;
            for (int i = 0; i < nums2.size(); i++)
            {
                mp[nums2[i]] = i;
            }

            vector<int> ans;
            for (int i = 0; i < nums1.size(); i++)
            {
                int curr = nums1[i];
                int var = -1;
                if (mp.count(curr))
                {
                    int ind = mp[curr];
                    for (int j = ind + 1; j < nums2.size(); j++)
                    {
                        if (nums2[j] > curr)
                        {
                            var = nums2[j];
                            break;
                        }
                    }
                    ans.push_back(var);
                }
            }
            return ans;
        }
};