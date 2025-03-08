class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        int minDiff = INT_MAX; int closest = 0;

        for(int i = 0; i < nums.size() - 2; i++){

            int j = i + 1; int k = nums.size() - 1;

            while(j < k){

                int sum = nums[i] + nums[j] + nums[k];

                if(sum == target) return sum;

                if(sum < target) j++;

                if(sum > target) k--;

                int diff = abs(sum - target);

                if(diff < minDiff){
                    minDiff = diff;
                    closest = sum;
                }
            }
        }

        return closest;
    }
};