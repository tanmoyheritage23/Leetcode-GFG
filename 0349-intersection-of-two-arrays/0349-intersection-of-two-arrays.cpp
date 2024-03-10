class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>freq(1001,0);
        vector<int>res;
        for(int it: nums1){
            if(!freq[it]){
                freq[it] = 1;
            }
        }
        
        for(int it: nums2){
            if(freq[it]!=2 && freq[it]!=0){
                res.push_back(it);
                freq[it] = 2;
            }
        }
        
        return res;
    }
};