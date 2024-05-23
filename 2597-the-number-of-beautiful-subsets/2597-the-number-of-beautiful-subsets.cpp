class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
       int count = 0;
        vector<int>subsets;
        countBeautifulSubsets(0,n,count,k,subsets,nums);
        return count-1; /* At the last index if I decided to not take any element then the empty string is also counted here that's why reducing vount by 1 */
    }
    
    void countBeautifulSubsets(int index, int n, int &count, int k, vector<int> &subsets, vector<int>&nums){
        if(index==n){
            count++;
            return;
        }
        
        /* Adding current element to the subsets */
        int current = nums[index];
        if(check(current,subsets,k)){   /* Checking if any number is present in subset or not whose difference with current  number equals to K */
            
            subsets.push_back(current);
            countBeautifulSubsets(index+1,n,count,k,subsets,nums);
            subsets.pop_back();
        }
        
        /* Skipping current element */
        countBeautifulSubsets(index+1,n,count,k,subsets,nums);
        
    }
    
    bool check(int current, vector<int> &subsets, int k){
        for(int num: subsets){
            if(abs(num-current)==k) return false;
        }
        return true;
    }
};