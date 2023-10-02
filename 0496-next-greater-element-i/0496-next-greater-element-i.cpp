class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {
            int n = nums2.size();
            unordered_map<int, int> mp;
            stack<int> st;

            for (int i = n - 1; i >= 0; i--)
            {
                while (!st.empty() && nums2[st.top()] <= nums2[i]) st.pop();
                if (!st.empty()) mp[nums2[i]] = st.top();
                else mp[nums2[i]] = n;
                st.push(i);
            }

            vector<int> ans;
            for (int i = 0; i < nums1.size(); i++)
            {
                int nextGreaterInd = mp[nums1[i]];
                if (nextGreaterInd == n) ans.push_back(-1);
                else ans.push_back(nums2[nextGreaterInd]);
            }

            return ans;
        }
};