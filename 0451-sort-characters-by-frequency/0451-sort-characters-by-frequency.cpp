class Solution {
    private:
    vector<pair<char,int>>sortByValue(unordered_map<char,int>&mp){
        vector<pair<char,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](const pair<char,int>&a,const pair<char,int>&b){
            return a.second > b.second;
        });
        return vec;
    }
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch: s){
            mp[ch]++;
        }
        
        vector<pair<char,int>>sortedChars = sortByValue(mp);
        string res;
        for(auto it: sortedChars){
            int i = 0;
            while(i < it.second){
                res += it.first;
                i++;
            }
        }
        
        return res;
    }
};