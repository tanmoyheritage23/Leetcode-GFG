class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, flipped = 0; // flipped help us to know before encountering any index how many times the flipped operation has taken place (odd or even)
        
        for(int &num: nums){
            if(num ^ flipped == 0){   // if nums[i] = 0 and flipped is even that means we need to flip that index to make it 1 and if nums[i] = 1 and flipped is odd that means we need to flip that index too because that 1 has become 0 after odd number of flip operation. At any other case we don't need to flip it.
                
                flipped ^= 1;
                ans++;
            }
        }
        
        return ans;
    }
};