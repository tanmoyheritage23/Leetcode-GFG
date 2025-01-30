class Solution {
public:
    string longestPalindrome(string s) {
    if(s.length()<=1){
        return s;
    }
        
        
    int max_len=1;int n=s.length();
    int st=0;int end=0;
        
    for(int i=0;i<n-1;i++){
    int l=i; int h=i+1;
     while(l>=0 && h<n){
            if(s[l]==s[h]){
                l--;
                h++;
            }else
                break;
        }
        int len=h-l-1;
        if(len>max_len){
            max_len=len;
            st=l+1;
            end=h-1;
        }
}

 for(int i=0;i<n-1;i++){
    int l=i; int h=i;
     while(l>=0 && h<n){
            if(s[l]==s[h]){
                l--;
                h++;
            }else
                break;
        }
        int len=h-l-1;
        if(len>max_len){
            max_len=len;
            st=l+1;
            end=h-1;
        }
 }
    
    return s.substr(st,max_len);
    
}
};