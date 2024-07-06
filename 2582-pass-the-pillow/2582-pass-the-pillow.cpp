class Solution {
public:
    int passThePillow(int n, int time) {
        int passingFirstToEndAndViceversa = time / (n-1);
        int movingBackwards = time % (n-1);
        
        int ans = 0;
        
        if(passingFirstToEndAndViceversa % 2 == 0){
            ans = movingBackwards + 1;
        }else{
            ans = n - movingBackwards;
        }
        
        return ans;
        
    }
};