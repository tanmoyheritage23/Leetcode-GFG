class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *max_element(nums.begin(),nums.end());
        int currMax = 1; int currMin = 1;
        for(int &num: nums){
            if(num==0){
                currMax = 1; currMin = 1;
                continue;
            }
            int tmp = currMax*num;
            currMax = max(max(tmp,currMin*num),num);
            currMin = min(min(tmp,currMin*num),num);
            res = max(res,currMax);
            
        }
        
        return res;
    }
};