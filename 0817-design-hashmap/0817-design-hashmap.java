public class ListNode{
        int key;
        int value;
        ListNode next;

        public ListNode(int key,int val, ListNode next){
            this.key = key;
            this.value = val;
            this.next = next;
        }

        public ListNode(){
            this(-1,-1,null);
        }
    }

class MyHashMap {
    private ListNode[] map;

    public MyHashMap() {
        map = new ListNode[1000];
        for(int i = 0; i < 1000; i++){
            map[i] = new ListNode();
        }
    }

    public int hash(int key){
        return key % map.length;
    }
    
    public void put(int key, int value) {
        ListNode curr = map[hash(key)];

        while(curr.next != null){
            if(curr.next.key == key){
                curr.next.value = value;
                return;
            }

            curr = curr.next;
        }

        curr.next = new ListNode(key,value,null);
    }
    
    public int get(int key) {
        ListNode curr = map[hash(key)].next;

        while(curr != null){
            if(curr.key == key){
                return curr.value;
            }

            curr = curr.next;
        }
        return -1;
    }
    
    public void remove(int key) {
        ListNode curr = map[hash(key)];

        while(curr.next != null){
            if(curr.next.key == key){
                curr.next = curr.next.next;
                return;
            }

            curr = curr.next;
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */