class Solution {
public:
    char kthCharacter(int k) {
        int operations = 1;
        int character = k;
        while(k>1){
            k = k/2;
            operations++;
        }
        string str = "a";
        for(int i = 0; i < operations; i++){
            string newStr="";
            for(char ch: str){
                newStr += (ch+1);
            }
            str+=newStr;
        }
        
        //cout<<str<<endl;
        
       return str[character-1];
    }
};