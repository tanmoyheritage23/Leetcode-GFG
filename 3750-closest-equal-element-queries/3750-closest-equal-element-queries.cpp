class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> answer(queries.size(), -1);

        
        unordered_map<int, vector<int>> valueToIndices;
        for (int i = 0; i < n; i++) {
            valueToIndices[nums[i]].push_back(i);
        }

        
        for (int i = 0; i < queries.size(); i++) {
            int queryIndex = queries[i];
            int queryValue = nums[queryIndex];

            const vector<int>& indices = valueToIndices[queryValue];

            
            if (indices.size() <= 1) continue;

            int minDistance = n; 
            int m = indices.size();
            int left = 0, right = 0;

            auto it = lower_bound(indices.begin(),indices.end(),queryIndex);
            int ind = it - indices.begin();

            if(ind == 0){
                right = abs(indices[ind]-indices[ind+1]);
                left = abs(n-indices[m-1]) + indices[0];
                
            }else if(ind == m-1){
                left = abs(indices[ind] - indices[ind-1]);
                right = abs(n-indices[ind]) + indices[0];
                
            }else{
                right = abs(indices[ind] - indices[ind+1]);
                left = abs(indices[ind] - indices[ind-1]);

            }

            minDistance = min(right,left);
            
            
            answer[i] = minDistance;
        }

        return answer;
    }
};