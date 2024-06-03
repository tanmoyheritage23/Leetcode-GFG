class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        int sPointer = 0, tPointer = 0;
        
        while(sPointer < n && tPointer < m){
            if(s[sPointer] == t[tPointer]){
                sPointer++;
                tPointer++;
            }
            else{
                sPointer++;
            }
        }
        
        return m - tPointer;
    }
};