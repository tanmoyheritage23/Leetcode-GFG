class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0, count = 0;
        while(i < haystack.length()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                count++;
            }else{
                i++;
                i = i-count;
                j = 0;
                count = 0;
            }
            
            if(count == needle.length()){
                return i-count;
            }
        }
        
        return -1;
        
    }
};