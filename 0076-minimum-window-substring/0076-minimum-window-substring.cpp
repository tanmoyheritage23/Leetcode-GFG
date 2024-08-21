class Solution {
public:
    string minWindow(string s, string t) {
        
       if(s.length() == 0 || t.length() == 0 || s.length() < t.length()) return "";
        
       vector<int>v(128,0);
                                               // Youtube link : https://youtu.be/rw660m-QLDo
       for(int i = 0; i < t.length(); i++){
           
           v[t[i]]++;
       }
        
        int st = 0; int end = 0; int ans_st = 0; int mini = INT_MAX; int count = 0;
        
        while(end < s.length()){
            
            if(v[s[end]] > 0) count++;
            v[s[end]]--;
            
            while(count == (int)t.length()){
                
                if(mini > end - st + 1){
                    
                    mini = end - st + 1;
                    ans_st = st;
                    
                }
                
                v[s[st]]++;
                if(v[s[st]] > 0) count--;
                st++;
                
            }
            
            end++;
        }
        
        if(mini == INT_MAX) return "";
        return s.substr(ans_st,mini);
    }
};