class Solution {
public:
typedef pair<int,int> PP;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<PP>>adj(n+1);
        for(auto &it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<PP,vector<PP>,greater<PP>>pq;
        vector<int>minTime(n+1,INT_MAX);

        pq.push({0,k});
        minTime[k] = 0;

        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &it: adj[node]){
                int neighbor = it.first;
                int weight = it.second;
                
                // Fix the update condition: update the neighbor, not the current node
                if (time + weight < minTime[neighbor]) {
                    minTime[neighbor] = time + weight;
                    pq.push({minTime[neighbor], neighbor});
                }
            }
        }
        
        int tm = INT_MIN;

        for(int i = 1; i <=n; i++){
            if(minTime[i] == INT_MAX){
                return -1;
            }
            //cout<<minTime[i]<<endl;
            tm = max(tm,minTime[i]);
        }

        return tm;
    }
};