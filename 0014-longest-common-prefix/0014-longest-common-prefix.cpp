class Solution {
    private:
    void insert(string &str, int trie[205][26], int &trieNodeCount, int endOfWord[]){
        int currentNode = 0;
        for(char ch: str){
            int charIndex = ch - 'a';
            if(trie[currentNode][charIndex] == 0){
                trieNodeCount++;
                trie[currentNode][charIndex] = trieNodeCount;
            }
            
            currentNode = trie[currentNode][charIndex];
        }

        endOfWord[currentNode] = 1;
    }

    string lcp(int trie[205][26], int endOfWord[]){
        string longest = "";
        int currentNode = 0;

        while(true){
            if (endOfWord[currentNode] == 1) break;
            int childrenCount = 0;
            int nextCharIndex = -1;

            for(int i = 0; i < 26; i++){
                if(trie[currentNode][i] != 0){
                    childrenCount++;
                    nextCharIndex = i;
                }
            }

            if(childrenCount != 1) break;

            longest += (char)(nextCharIndex + 'a');
            currentNode = trie[currentNode][nextCharIndex];
        }

        return longest;
        
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int trieNodeCount = 0;
        int trie[205][26] = {};
        int endOfWord[205] = {};

        for(string &str: strs){
            if(str.empty()) return "";
            insert(str,trie,trieNodeCount,endOfWord);
        }

        string res = lcp(trie,endOfWord);

        return res;
    }
};