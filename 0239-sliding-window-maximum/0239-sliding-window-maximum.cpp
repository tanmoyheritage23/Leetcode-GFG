class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            int n = nums.size();
            deque<int> dq;
            vector<int> res;

            for (int i = 0; i < n; i++)
            {
               	// removing out of bound elements
                if (!dq.empty() && dq.front() == i - k) dq.pop_front();

               	// removing elements which are smaller than my current nums[i] cuz they don't matter in
               	//monotonic decreasing queue
                while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

                dq.push_back(i);

               	// for every window k we are storing max element
                if (i >= k - 1) res.push_back(nums[dq.front()]);
            }

            return res;
        }
};