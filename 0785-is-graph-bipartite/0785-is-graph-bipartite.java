class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] colors = new int[n];
        Arrays.fill(colors,-1);

        for(int i = 0; i < n; i++){
            if(colors[i] == -1){
                Queue<Integer>q = new LinkedList<>();
                q.add(i);
                colors[i] = 1;

                while(!q.isEmpty()){
                    int node = q.poll();

                    for(int neighbour: graph[node]){
                        if(colors[neighbour] == -1){
                            colors[neighbour] = 1 - colors[node];
                            q.add(neighbour);
                        }else{
                            if(colors[neighbour] == colors[node]) return false;
                        }
                    }
                }
            }
        }

        return true;
    }
}