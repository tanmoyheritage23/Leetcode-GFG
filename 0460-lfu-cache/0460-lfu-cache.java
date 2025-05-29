class LFUCache {

    class Node{
        int key,val,freq;
        public Node(int k, int v){
            this.key = k;
            this.val = v;
            this.freq = 1;
        }
    }

    private final int cap;
    private int minFreq;
    private Map<Integer,Node>keyMap;
    private Map<Integer,LinkedHashSet<Node>>freqMap;

    public LFUCache(int capacity) {
        this.cap = capacity;
        //this.minFreq = 0;
        this.keyMap = new HashMap<>();
        this.freqMap = new HashMap<>();
    }
    
    public int get(int key) {
        if(!keyMap.containsKey(key)) return -1;
        Node node = keyMap.get(key);
        int value = node.val;
        updateFreq(node);
        return value;
    }
    
    public void put(int key, int value) {
        if(keyMap.containsKey(key)){
            Node node = keyMap.get(key);
            node.val = value;
            updateFreq(node);
            
        }else{
            if(keyMap.size() == cap){
                LinkedHashSet<Node>LFU = freqMap.get(minFreq);
                Node toRemove = LFU.iterator().next();
                LFU.remove(toRemove);
                keyMap.remove(toRemove.key);
                if(LFU.isEmpty()) freqMap.remove(minFreq);
            }
            Node newNode = new Node(key,value);
            keyMap.put(key,newNode);
            freqMap.computeIfAbsent(1,x->new LinkedHashSet<>()).add(newNode);
            minFreq = 1;

        }
    }

    private void updateFreq(Node node){
        int oldFreq = node.freq;
        LinkedHashSet<Node>oldSets = freqMap.get(oldFreq);
        oldSets.remove(node);
        if(oldSets.isEmpty()){
            freqMap.remove(oldFreq);
            if(oldFreq == minFreq) minFreq++;
        }
        node.freq++;
        freqMap.computeIfAbsent(node.freq, x-> new LinkedHashSet<>()).add(node);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */