class Solution {
    unordered_map<int,int>dp;
private:
    int memoize(int n){
        if(n <= 1 ) return n;

        if(dp[n] != 0) return dp[n];

        int divBy2 = 1 + (n%2 + memoize(n/2));
        int divBy3 = 1 + (n%3 + memoize(n/3));

        return dp[n] = min(divBy2,divBy3);
    }
public:
    int minDays(int n) {
        return memoize(n);
    }
};