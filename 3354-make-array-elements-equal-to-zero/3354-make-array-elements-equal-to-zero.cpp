class Solution {
    private:
    int validCount(vector<int>nums, int currInd, bool dir){
        int n = nums.size();
        while(currInd >= 0 && currInd < n){
            if(nums[currInd]==0){
                currInd += (dir==true)?1:-1;
                
            }else{
                nums[currInd]--;
                dir = !dir;
                currInd += (dir==true)?1:-1;
            }
        }
        
        for(int num: nums){
            if(num != 0) return 0;
        }
        
        return 1;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]==0){
                count += validCount(nums,i,true) + validCount(nums,i,false);
            }
        }
        return count;
    }
};