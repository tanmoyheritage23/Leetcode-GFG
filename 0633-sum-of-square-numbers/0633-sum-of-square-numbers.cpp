class Solution
{
    public:
        bool judgeSquareSum(int c)
        {

            for (long a = 0; a * a <= c; a++)
            {
                int b = c - (int)(a *a);
                if (binarySearch(0, b, b))
                {
                    return true;
                }
            }

            return false;
        }

    private:
        bool binarySearch(long low, long high, long target)
        {

            while (low <= high)
            {
                long mid = low + (high - low) / 2;

                if (mid *mid == target) return true;

               else if (mid * mid < target) low = mid + 1;

               else high = mid - 1;
        }

    return false;
}
};