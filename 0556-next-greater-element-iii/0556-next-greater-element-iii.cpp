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
        
        for(int i = firstDeflectionPoint+1; i < len; i++){ // we want a number which is just greater than the num[firstDeflectionPoint] cuz we need to find smallest number which is just greater than n or num so to say
            if(num[i]-'0'>num[firstDeflectionPoint]-'0'){
                secondDeflectionPoint = i;
            }
        }
        
        swap(num[firstDeflectionPoint], num[secondDeflectionPoint]);
        sort(num.begin()+firstDeflectionPoint+1,num.end()); // try this example 1432
        
        long long ans = stoll(num);
        
        return ans>INT_MAX?-1:ans;
    }
};