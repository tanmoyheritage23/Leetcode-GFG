class Node{
    int key;
    int val;
    Node next;
    Node prev;

    public Node(int key, int val){
        this.key = key;
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class LRUCache {
    private int cap;
    private Map<Integer,Node>mp;
    private Node head;
    private Node tail;

    public LRUCache(int capacity) {
        this.cap = capacity;
        this.mp = new HashMap<>();
        this.head = new Node(-1,-1);
        this.tail = new Node(-1,-1);
        this.head.next = tail;
        this.tail.prev = head;
    }

    public void insert(Node node){
        Node temp = head.next;
        node.prev = head;
        head.next = node;
        node.next = temp;
        temp.prev = node;
    }

    public void delete(Node node){
        Node prevNode = node.prev;
        Node nextNode = node.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }
    
    public int get(int key) {
        if(mp.containsKey(key)){
            Node node = mp.get(key);
            delete(node);
            insert(node);
            return node.val;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(mp.containsKey(key)){
            Node node = mp.get(key);
            delete(node);
            node.val = value;
            insert(node);
            mp.put(key,node);
        }else{
            if(mp.size() == cap){
               Node lru = tail.prev;
               delete(lru);
               mp.remove(lru.key);
            }
            Node newNode = new Node(key,value);
            insert(newNode);
            mp.put(key,newNode);
        }
        
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */