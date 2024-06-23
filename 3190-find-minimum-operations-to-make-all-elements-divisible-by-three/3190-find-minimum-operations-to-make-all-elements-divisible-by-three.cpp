class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minMoves = 0;
        for(int num: nums){
            int rem = num%3;
            minMoves += min(rem,3-rem);
        }
        
        return minMoves;
    }
};