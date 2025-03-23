class Solution {
    
public:
#define ll long long
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();
        ll ans = 0;

        for(int i = 0; i < n; i++){
            ll st = queries[i][0], end = queries[i][1];
            ll ops = 0;
            for(ll d = 1, prev = 1; d < 17; d++){
                ll curr = prev * 4LL;
                ll l = max(prev,st);
                ll r = min(end,curr-1);

                if(l > end) break;
                
                if(r >= l) ops += (r-l+1) * d;
                prev = curr;
            }

            ans += (ops+1)/2;
        }

        return ans;
    }
};