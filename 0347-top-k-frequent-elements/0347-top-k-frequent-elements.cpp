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
    
    /* QuickSelect Algorithm */
    
     vector<int> topKFrequent(vector<int>& nums, int k){
         
         unordered_map<int,int>mp;
         for(int it: nums) mp[it]++;
         
         // copying the elements into an array for quickselect procedure
         
         vector<pair<int,int>>vec;
         for(auto it: mp) vec.push_back({it.first,it.second});  // {element,frequency}
         
         int n = vec.size();
         int left = 0; int right = n - 1;
         int pivotIndex;
         //We know that once you select a pivot, and partition the array to find it's final position, all the elements to the left of the pivot are smaller than it,
         //and all the elements to the right are larger than it.
         
         //Now if we end up partitioning the array at exactly n - k position i.e. we choose a pivot element in such a way that its final position is at n - k index 
         //because then only all the elements to its right will have k greatest frequency elements (we are sorting based on frequency)
         while(left <= right){
           pivotIndex = partition(vec,left,right);
           
             if(pivotIndex == n - k) break;
             
             else if(pivotIndex > n - k) right = pivotIndex - 1;
             
             else left = pivotIndex + 1;
             
         }
         
         int k = 0;
         vector<int>res(k);
         for(int i = pivotIndex; i < n; i++){
             res[k++] = vec[i].first;
         }
         
         return res;
     }
    
    int partition(vector<pair<int,int>>& vec, int left, int right){
        int i = left; auto pivot = vec[right];
        for(int j = left; j <= right - 1; j++){
            if(vec[j].second <= pivot.second){
                swap(vec[j],vec[i]);
                i++;
            }
        }
        swap(vec[i],vec[right]);
        return i;
    }
};
