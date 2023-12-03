class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end()); 
    int maxReachable = 0; 
    int coinsNeeded = 0; 

    for (int coin : coins) {
        
        while (maxReachable + 1 < coin) {
            coinsNeeded++;
            maxReachable += (maxReachable + 1); // Add the coin to the array
            if (maxReachable >= target) {
                return coinsNeeded; // Return the count of coins needed if target is reached
            }
        }

        maxReachable += coin; // Update the maximum reachable value

        if (maxReachable >= target) {
            return coinsNeeded; 
        }
    }

    // If the maximum reachable value is less than the target, add coins up to the target
    while (maxReachable < target) {
        coinsNeeded++;
        maxReachable += (maxReachable + 1); 
    }

    return coinsNeeded;
    }
};