class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
       int n = deck.size();
        vector<int>result(n,0);
        
        int i = 0; // deck
        int j = 0; // result
        bool skip = false;
        
        sort(deck.begin(),deck.end());
        
        while(i < n){
            if(result[j]==0){
                if(skip==false){
                    result[j]=deck[i];
                    i++;
                }
                
                skip = !skip;
            }
            
            j = (j+1)%n;
        }
        
        return result;
    }
};