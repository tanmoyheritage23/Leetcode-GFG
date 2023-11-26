class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>final =mat;
        int n = mat.size();
        for(int i = 0; i < n; i++){
           if(i%2 != 0){
               for(int j =0; j < k; j++){
                   int last = mat[i][mat[i].size()-1];
                   mat[i].pop_back();
                   mat[i].insert(mat[i].begin(),last);
               }
           } 
           else{
                for(int j = 0; j < k; j++){
                    int first = mat[i][0];
                    mat[i].erase(mat[i].begin());
                    mat[i].push_back(first);
                }
            }
        }
        
        return mat==final;
    }
};