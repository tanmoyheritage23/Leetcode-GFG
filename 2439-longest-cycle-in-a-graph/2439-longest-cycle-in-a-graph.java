class Solution {
    private void dfs1(int node, Stack<Integer> st, int[] vis, List<List<Integer>> adj) {
        vis[node] = 1;
        for (int it : adj.get(node)) {
            if (vis[it] == 0) {
                dfs1(it, st, vis, adj);
            }
        }
        st.push(node);
    }

    private void dfs2(int node, List<Integer> components, int[] vis, List<List<Integer>> adjT) {
        vis[node] = 1;
        components.add(node);
        for (int it : adjT.get(node)) {
            if (vis[it] == 0) {
                dfs2(it, components, vis, adjT);
            }
        }
    }

    public int longestCycle(int[] edges) {
        int n = edges.length;
        List<List<Integer>> adj = new ArrayList<>();
        List<List<Integer>> adjT = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
            adjT.add(new ArrayList<>());
        }

        for (int u = 0; u < n; u++) {
            int v = edges[u];
            if (v != -1) {
                adj.get(u).add(v);
                adjT.get(v).add(u);
            }
        }

        Stack<Integer> st = new Stack<>();
        int[] vis = new int[n];
        int maxi = -1;

        // First DFS to fill the stack
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs1(i, st, vis, adj);
            }
        }

        // Reset vis array for second DFS
        vis = new int[n];

        // Second DFS to find SCCs and check for cycles
        while (!st.isEmpty()) {
            int node = st.pop();
            if (vis[node] == 0) {
                List<Integer> components = new ArrayList<>();
                dfs2(node, components, vis, adjT);

                // Check for cycle in SCC
                if (components.size() > 1) {
                    maxi = Math.max(maxi, components.size());
                } else {
                    // For single node, check if it has a self-loop
                    int next = edges[components.get(0)];
                    if (next == components.get(0)) {
                        maxi = Math.max(maxi, 1);
                    }
                }
            }
        }

        return maxi;
    }
}