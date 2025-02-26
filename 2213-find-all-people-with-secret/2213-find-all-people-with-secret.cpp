class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // Sort meetings by time
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        unordered_set<int> visited = {0, firstPerson};
        int i = 0;
        
        while (i < meetings.size()) {
            // Collect all meetings at the same time
            int currentTime = meetings[i][2];
            unordered_map<int, vector<int>> graph;
            while (i < meetings.size() && meetings[i][2] == currentTime) {
                graph[meetings[i][0]].push_back(meetings[i][1]);
                graph[meetings[i][1]].push_back(meetings[i][0]);
                i++;
            }
            
            // Find all reachable people in this connected component
            unordered_set<int> currentVisited;
            queue<int> q;
            
            // Add initially visited people to the queue
            for (const auto& [person, _] : graph) {
                if (visited.count(person)) {
                    q.push(person);
                    currentVisited.insert(person);
                }
            }
            
            // BFS to mark all reachable nodes
            while (!q.empty()) {
                int person = q.front();
                q.pop();
                
                for (int neighbor : graph[person]) {
                    if (!currentVisited.count(neighbor)) {
                        currentVisited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            
            // Add the newly visited people to the global visited set
            visited.insert(currentVisited.begin(), currentVisited.end());
        }
        
        return vector<int>(visited.begin(), visited.end());
    }
};