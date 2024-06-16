class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long count = 0;
        unordered_map<int,long long>mp;
        int n = hours.size();
        
        for(int i = 0; i < n; i++){
            int first = hours[i]%24;
            int second = 0;
            (first==0) ? second = 0 : second = 24-first;
            
            if(mp.find(second) != mp.end()){
                count += mp[second];
            }
            
            mp[first]++;
        }
        
        return count;
    }
};