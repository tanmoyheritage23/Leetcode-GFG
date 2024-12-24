class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>pq;
        for(int stoneWeight: stones){
            pq.push(stoneWeight);
        }
        
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first >= second){
                first = first - second;
                pq.push(first);
            }
        }
        
        return pq.top();
    }
};