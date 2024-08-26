class Solution {
    const int mod = 1e9+7;
    int modpow(long base, int exp) {
        long result = 1;
        while (exp) {
            if (exp & 1) {
                result *= base;
                result %= mod;
            }
            base *= base;
            base %= mod;
            exp >>= 1;
        }
        return result;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mult) {
        if(mult == 1)
            return nums;
        int n = nums.size();
        const long mx = *max_element(nums.cbegin(), nums.cend());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for(int i=0;i<n;i++){
            pq.push(make_pair(nums[i],i));
        }
        while (k && 1LL*mult *pq.top().first <= mx) {
            --k;
            pq.push(make_pair((mult * pq.top().first)%mod, pq.top().second));  pq.pop();
        }
        const long pow = modpow(mult, k / n);
        while (!pq.empty()) {
            int val = pq.top().first;
            int ind = pq.top().second; pq.pop();

            if (k % n) {
                --k;
                nums[ind] = ((1LL*mult * pow)%mod * val)%mod; 
            } else {
                nums[ind] = (1LL*pow * val)%mod;
            }
        }
        return nums;
    }   
};