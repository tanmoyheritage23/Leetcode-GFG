class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int st = 0, end = 0, ans = 0;
        
        while(end<n){
            maxCost -= abs(s[end]-t[end]);
            while(maxCost < 0){
               maxCost += abs(s[st]-t[st]);
                st++;
            }
            ans = max(ans,end-st+1);
            end++;
        }
        
        return ans;
    }
};