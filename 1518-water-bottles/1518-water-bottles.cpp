class Solution
{
    public:
        int numWaterBottles(int numBottles, int numExchange)
        {
            int maxi = numBottles;
            int waterBottles = 0, emptyBottles = 0;
            while (numBottles >= numExchange)
            {
                waterBottles = numBottles / numExchange;
                emptyBottles = numBottles % numExchange;
                maxi += waterBottles;
                numBottles = waterBottles + emptyBottles;
            }
            
            return maxi;
        }
};