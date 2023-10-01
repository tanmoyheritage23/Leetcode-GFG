class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int len = num.length();
        int firstDeflectionPoint, secondDeflectionPoint = -1;
        int curr = num[len-1]-'0';
        for(int i = len-2; i>=0; i--){
            if(num[i]-'0'<curr){
                firstDeflectionPoint = i;
                break;
            }
            curr = num[i]-'0';
        }
        
        if(firstDeflectionPoint == -1) return -1;
        
        for(int i = firstDeflectionPoint+1; i < len; i++){
            if(num[i]-'0'>num[firstDeflectionPoint]-'0'){
                secondDeflectionPoint = i;
            }
        }
        
        swap(num[firstDeflectionPoint], num[secondDeflectionPoint]);
        sort(num.begin()+firstDeflectionPoint+1,num.end());
        
        long long ans = stoll(num);
        
        return ans>INT_MAX?-1:ans;
    }
};