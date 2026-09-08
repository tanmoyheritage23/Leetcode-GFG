class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        // Build adjacency list
        Map<Integer, List<int[]>> graph = new HashMap<>();
        for (int[] t : times) {
            graph.computeIfAbsent(t[0], x -> new ArrayList<>()).add(new int[] { t[1], t[2] });
        }

        // Dijkstra's algorithm
        Map<Integer, Integer> distances = new HashMap<>();
        distances.put(k, 0);
        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        heap.offer(new int[] { 0, k });

        while (!heap.isEmpty()) {
            int[] curr = heap.poll();
            int dist = curr[0], node = curr[1];

            if (dist > distances.getOrDefault(node, Integer.MAX_VALUE))
                continue;

            for (int[] edge : graph.getOrDefault(node, new ArrayList<>())) {
                int neighbor = edge[0], weight = edge[1];
                int newDist = dist + weight;
                if (newDist < distances.getOrDefault(neighbor, Integer.MAX_VALUE)) {
                    distances.put(neighbor, newDist);
                    heap.offer(new int[] { newDist, neighbor });
                }
            }
        }

        if (distances.size() != n)
            return -1;
        return Collections.max(distances.values());
    }
}