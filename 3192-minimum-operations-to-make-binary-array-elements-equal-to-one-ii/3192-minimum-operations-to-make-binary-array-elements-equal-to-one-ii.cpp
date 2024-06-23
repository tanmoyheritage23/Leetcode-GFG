class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, flipped = 0;
        
        for(int &num: nums){
            if(num ^ flipped == 0){
                
                flipped ^= 1;
                ans++;
            }
        }
        
        return ans;
    }
};