class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
       unordered_map<char,unordered_set<string>>mp;
        for(const string &s: ideas){
            char key = s[0];
            string val = s.substr(1);
            mp[key].insert(val);
        }
        long long res = 0;
        for(auto &[key1,set1]: mp){
            for(auto &[key2,set2]:mp){
                if(key1==key2) continue;
                int overlap = 0;
                for(const string &s: set1){
                    if(set2.count(s)) overlap++;
                }
                int distinct1 = set1.size() - overlap;
                int distinct2 = set2.size() - overlap;
                res += static_cast<long long>(distinct1 * distinct2);
            }
        }
        
        return res;
    }
};