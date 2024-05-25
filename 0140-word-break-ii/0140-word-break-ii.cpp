class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        string currSentence = "";
        vector<string>result;
        findSentences(0,s,st,currSentence,result);
        return result;
    }
    
private: 
    void findSentences(int index, string s, unordered_set<string>& st, string &currSentence, vector<string>&result){
        
        if(index == s.length()){
            result.push_back(currSentence);
            return;
        }
        
        for(int j = index; j < s.length(); j++){
            string word = s.substr(index,j-index+1);
            if(st.count(word)){
                string tempSentence = currSentence;
                if(!currSentence.empty()) currSentence += " ";
                currSentence += word; // including the word
                findSentences(j+1,s,st,currSentence,result);
                currSentence = tempSentence; // backtracking to previous step
                
            }
        }
        
        
    }
};