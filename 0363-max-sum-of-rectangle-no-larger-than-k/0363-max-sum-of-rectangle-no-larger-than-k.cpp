class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& m, int k) {
        
        int rows = m.size();
        int cols = m[0].size();
        int res = INT_MIN;
        
        for(int l = 0; l < cols; l++){
            
            vector<int>sums(rows,0);
            
            for(int r = l; r < cols; r++){
                
                for(int i = 0; i < rows; i++){
                    
                    sums[i] += m[i][r];
                }
                
                int run_sum = 0; set<int>s = {0};
                
                for(int sum : sums){
                    
                    run_sum += sum;
                    
                    auto it = s.lower_bound(run_sum - k);
                    
                    if(it != s.end())
                        res = max(res, run_sum - *it);
                    
                    s.insert(run_sum);
                }
            }
        }
        
        return res;
    }
};