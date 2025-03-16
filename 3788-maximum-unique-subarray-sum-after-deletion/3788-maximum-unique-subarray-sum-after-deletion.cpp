class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool allNegative = true;
        int maxNegative = INT_MIN;
        int positiveSum = 0;
        unordered_set<int>unique;

        for (int num : nums) {
            if (num >= 0) {
                allNegative = false;
                unique.insert(num);
            } else {
                maxNegative = std::max(maxNegative, num);
            }
        }

        for(int sum: unique){
            positiveSum += sum;
        }

        return allNegative ? maxNegative : positiveSum;
    }
};