class Solution
{
    public:
        int numRescueBoats(vector<int> &people, int limit)
        {
            vector<int>mp(30001,0);

            for (int p: people) mp[p]++;

            
            int ans = 0;

           for(int i = 0; i < people.size(); i++){
               if(mp[people[i]]){
                   int remaining = limit - people[i];
               mp[people[i]]--;
               while(mp[remaining] == 0 && remaining > 0){
                   remaining--;
               }
               if(remaining > 0) mp[remaining]--;
               ans++;
               }
           }
            return ans;
        }
};