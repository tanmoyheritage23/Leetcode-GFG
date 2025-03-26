class Trie {
    private static final int MaxNodes = 600000;
    private static final int ALPHABET_SIZE = 26;

    private int[][] trie;
    private int[] endOfWord;
    private int trieNodeCount;

    public Trie() {
        trie = new int[MaxNodes][ALPHABET_SIZE];
        endOfWord = new int[MaxNodes];
        trieNodeCount = 0;
    }
    
    public void insert(String word) {
        int currentNode = 0;
        for(char ch: word.toCharArray()){
            int charIndex = ch - 'a';
            if(trie[currentNode][charIndex] == 0){
                trieNodeCount++;
                trie[currentNode][charIndex] = trieNodeCount;
            }
            
            currentNode = trie[currentNode][charIndex];
        }

        endOfWord[currentNode] = 1;
    }
    
    public boolean search(String word) {
        int currentNode = 0;
        for(char ch: word.toCharArray()){
            int charIndex = ch - 'a';
            if(trie[currentNode][charIndex] == 0) return false;
            currentNode = trie[currentNode][charIndex];
        }
        return endOfWord[currentNode] == 1;
    }
    
    public boolean startsWith(String prefix) {
        int currentNode = 0;
        for(char ch: prefix.toCharArray()){
            int charIndex = ch - 'a';
            if(trie[currentNode][charIndex] == 0) return false;
            currentNode = trie[currentNode][charIndex];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */