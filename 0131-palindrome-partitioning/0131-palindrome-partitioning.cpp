class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>path;
        palindromePartitioning(0,s,path,res);
        return res;
    }
    
    void palindromePartitioning(int index, string s, vector<string> &path, vector<vector<string>> &res){
        if(index == s.length()){
            res.push_back(path);
            return;
        }
        
        for(int i = index; i < s.length(); i++){
            if(isPalindrome(s,index,i)){
                path.push_back(s.substr(index, i-index+1));
                palindromePartitioning(i+1,s,path,res);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};