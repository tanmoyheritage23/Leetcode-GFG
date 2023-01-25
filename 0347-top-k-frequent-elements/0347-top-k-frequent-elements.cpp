class Solution {
public:
    
   /* T.C -> O(NlogN) , S.C -> O(N)
    
  bool static comp(pair<int,int>&a, pair<int,int>&b){
      return a.second > b.second;
  }  
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<pair<int,int>>v;
        int n = nums.size();
        
        for(int i = 0 ; i < n; i++){
            mp[nums[i]]++;
        }
        
        for(auto it: mp) v.push_back(it);
        
        sort(v.begin(),v.end(),comp);
        
        vector<int>temp;
        
        for(auto it: v){
            
            if(k == 0) return temp;
            
            temp.push_back(it.first);
            k--;
        }
        
        return temp;
    }
    */
    /* T.C -> O(Nlog(N-K)), S.C -> O(N) */
     vector<int> topKFrequent(vector<int>& nums, int k){
         
         unordered_map<int,int>mp;
         
         for(auto it: nums) mp[it]++;
         
         priority_queue<pair<int,int>>pq;
         vector<int>res;
         
         for(auto it: mp){
             pq.push({it.second,it.first});
             if(pq.size() > (int)mp.size() - k){
                 res.push_back(pq.top().second);
                 pq.pop();
             }
         }
         
         return res;
     }
};