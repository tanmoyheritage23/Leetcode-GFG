class Solution {
public:
    int winnerIdx(int n, int k){
        if(n==1) return 0; // index of the  modified array
        
        int idx = winnerIdx(n-1,k);
        idx = (idx + k) % n ;// original index of the original array
        return idx;
    }
    int findTheWinner(int n, int k) {
       int result_idx = winnerIdx(n,k);
        return result_idx + 1;
    }
};