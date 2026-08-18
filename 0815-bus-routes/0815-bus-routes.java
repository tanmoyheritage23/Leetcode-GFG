class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if(source == target) return 0;
        Map<Integer, List<Integer>>mp = new HashMap<>();
        for(int i = 0; i < routes.length; i++){
            for(int route: routes[i]){
                mp.computeIfAbsent(route, k -> new ArrayList<>()).add(i);
            }
        }

        Queue<int[]>q = new LinkedList<>();
        Set<Integer>visited = new HashSet<>();
        for(int bus: mp.getOrDefault(source,new ArrayList<>())){
            q.offer(new int[]{bus,1});
            visited.add(bus);
        }

        while(!q.isEmpty()){
            int[] current = q.poll();
            int bus = current[0];
            int busChangeCount = current[1];

            for(int stop: routes[bus]){
                if(stop == target) return busChangeCount;

                for(int connectedBus: mp.get(stop)){
                    if(!visited.contains(connectedBus)){
                        q.offer(new int[]{connectedBus, busChangeCount+1});
                        visited.add(connectedBus);
                    }
                }
            }

            
        }

        return -1;


    }
}