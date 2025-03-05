class Solution {
public:
    string minRemoveToMakeValid(string s) {
       int n = s.length();
       int openBracket = 0;
        
        // handling excess closing bracket
        for(int i = 0; i < n; i++){
            if(s[i]=='(') openBracket++;
            else if(s[i]==')'){
                if(openBracket==0) s[i]='*';
                else openBracket--;
            }
        }
        
        // handling excess opening bracket
        for(int i = n-1; i >= 0; i--){
            if(openBracket>0 && s[i]=='('){
                s[i]='*';
                openBracket--;
            }
            
        }
        
        cout<<s<<endl;
        
        string res ="";
        for(char ch: s){
           if(ch!='*') res += ch; 
        }
        
        return res;
    }
};