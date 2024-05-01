class Solution {
    private:
    int compute(vector<int>&nums,int k, int end){
        int res = lower_bound(nums.begin(),nums.begin()+end,k)-nums.begin();
        //ut<<res<<endl;
        return res;
    }
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int pairs = 0;
        for(int i = 1; i < n; i++){
            pairs += compute(nums,target-nums[i],i);
        }
        return pairs;
    }
};