class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {
            stack<int> st;
            unordered_map<int, int> mp;
            int n = nums2.size();
            for (int i = n - 1; i >= 0; i--)
            {
            	// itreting from n to 0 because we want next greater element
                int curr = nums2[i];
               	// pushing elements into the stack in decreasing order
                while (!st.empty() && curr > st.top()) st.pop();
               	// if anytime stack becomes empty that means there is no next greater element exists 
               	// for my current element
                if (st.empty()) mp[curr] = -1;
               	// if not then then top element of the stack will be my next greater element for my 
               	// current element because the stack is in monotonic decreasing order
                else mp[curr] = st.top();
               	// And most importantly before going for another iteration make sure you push your
               	// current element into the stack
                st.push(curr);
            }
            vector<int> ans;
            for (int num: nums1)
            {
                ans.push_back(mp[num]);
            }

            return ans;
        }
};