class Solution {
    // watch codestorywithmik for detailed explanation
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int>isFlipped(n,false);
        int flipCountAtCurri = 0;
        
        for(int i = 0; i < n; i++){
            if(i >= k && isFlipped[i-k]){
                flipCountAtCurri--;
            }
            
            if(flipCountAtCurri % 2 == nums[i]){
                if(i+k > n) return -1;
                
                flipCountAtCurri++;
                ans++;
                isFlipped[i] = true;
            }
        }
        return ans;
    }
};