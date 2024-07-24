class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>vec;
        vector<int>answer;
        for(int i = 0; i < n; i++){
            string currStr = to_string(nums[i]);
            string newStr = "";
            for(char ch: currStr){
                newStr += to_string(mapping[ch-'0']);
            }
            int mappedValue = stoi(newStr);
            vec.push_back({mappedValue,i});
            
        }
        
        sort(vec.begin(),vec.end());
        for(auto pair: vec){
            answer.push_back(nums[pair.second]);
        }
        return answer;
    }
};