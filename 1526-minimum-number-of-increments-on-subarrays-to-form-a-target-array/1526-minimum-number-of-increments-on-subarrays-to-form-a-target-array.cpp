class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        
        int operations = 0, curr = 0, prev = 0;
        for(int i = 0; i < n; i++){
            curr = target[i];
            
            if(curr > prev){
                operations += curr - prev;
            }
            prev = curr;
        }
        
        return operations;
    }
};