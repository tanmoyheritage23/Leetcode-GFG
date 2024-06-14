class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        set<int>mySet;
        sort(nums.begin(),nums.end());
        int minMoves = 0, ans = 0;
        
        for(int i = 0; i < n; i++){
            if(!mySet.empty() && mySet.find(nums[i]) != mySet.end()){
                int maxi = *mySet.rbegin();
                minMoves = (maxi-nums[i]) + 1;
                mySet.insert(nums[i]+minMoves);
                 ans += minMoves;
            }
            if(mySet.empty() || mySet.find(nums[i]) == mySet.end()){
                mySet.insert(nums[i]);
            }
            
            
            
           
        }
        
        return ans;
        
    }
};