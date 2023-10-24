class Solution
{
    private:
        int partition(int guessed_partition_size, vector<int> &frequencies)
        {
            int result = 0;
            for (int frequency: frequencies)
            {
                int num_groups = frequency / guessed_partition_size;
                int remainder = frequency % guessed_partition_size;
                if (remainder > num_groups)
                {
                    return INT_MAX;
                }

                result += ceil(static_cast<double>(frequency) / (guessed_partition_size + 1));
            }
            return result;
        }

    public:
        int minGroupsForValidAssignment(vector<int> &nums)
        {
            unordered_map<int, int> counts;
            for (int num: nums)
            {
                counts[num]++;
            }

            vector<int> frequencies;
            for (auto entry: counts)
            {
                frequencies.push_back(entry.second);
            }

            if (frequencies.size() == 1)
            {
                return 1;
            }

            int result = nums.size();	// worst case is all nums are unique
            int least_frequent = *min_element(frequencies.begin(), frequencies.end());

            for (int partition_size = least_frequent; partition_size >= 1; partition_size--)
            {
                result = min(result, partition(partition_size, frequencies));
            }

            return result;
        }
};