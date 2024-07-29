class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;
        
        for(int j = 1; j < n - 1; j++){
            
            int countSmallerLeft = 0;
            int countLargerLeft = 0;
            int countSmallerRight = 0;
            int countLargerRight = 0;
            
            // Strictly increasing
            for(int i = 0; i < j; i++){
                
                if(rating[i] < rating[j]){
                    countSmallerLeft++;
                }else{
                    countLargerLeft++;
                }
            }
            
            //Strictly decreasing
            
            for(int k = j+1; k < n; k++){
                
                if(rating[j] > rating[k]){
                    countSmallerRight++;
                }else{
                    countLargerRight++;
                }
            }
            
            teams += (countSmallerLeft * countLargerRight) + (countLargerLeft * countSmallerRight);
        }
        
        return teams;
    }
};