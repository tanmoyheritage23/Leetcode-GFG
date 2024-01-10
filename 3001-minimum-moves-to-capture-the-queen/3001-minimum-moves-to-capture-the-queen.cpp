class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int minMoves = 2;
       if(a==e && !(a==c && d > min(b,f) && d < max(b,f))) return 1;
        if(b==f && !(b==d && c > min(a,e) && c < max(a,e))) return 1;
        if(abs(c-e)==abs(d-f) && !(abs(a-c)==abs(b-d) && a > min(c,e) && a < max(c,e) && b > min(d,f) && b < max(d,f))) return 1;
        return minMoves;
        
    
    }
};