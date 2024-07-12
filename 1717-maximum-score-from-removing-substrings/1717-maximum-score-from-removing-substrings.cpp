class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string highPriorityString = x > y ? "ab" : "ba";
        string lowPriorityString = highPriorityString == "ab" ? "ba" : "ab";
        
        string stringAfterFirstPass = removeString(s,highPriorityString);
        int removedPairCount = (s.length() - stringAfterFirstPass.length()) / 2;
        totalScore += removedPairCount * max(x,y);
        
        string stringAfterSecondPass = removeString(stringAfterFirstPass,lowPriorityString);
        removedPairCount = (stringAfterFirstPass.length() - stringAfterSecondPass.length()) / 2;
        totalScore += removedPairCount * min(x,y);
        
        return totalScore;
        
        
    }
    
    private:
        string removeString(string &input, string &targetPair){
            stack<char>charStack;
            
            for(char ch: input){
                if(!charStack.empty() && ch == targetPair[1] && charStack.top()==targetPair[0]){
                    charStack.pop();
                }else{
                    charStack.push(ch);
                }
            }
            
            string remainingString = "";
            while(!charStack.empty()){
                remainingString += charStack.top();
                charStack.pop();
            }
            
            reverse(remainingString.begin(),remainingString.end());
            return remainingString;
        }
};