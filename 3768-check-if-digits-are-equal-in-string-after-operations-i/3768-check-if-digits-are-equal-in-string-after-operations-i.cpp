class Solution {
public:
    bool hasSameDigits(string s) {
        int totalOperations = s.length() - 2;

        while(totalOperations--){

            for(int i = 0; i < s.length() - 1; i++){
                s[i] = (s[i] + s[i+1]) % 10;
            }
        }

        return s[0]==s[1];
    }
};