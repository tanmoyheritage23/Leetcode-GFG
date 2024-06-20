class Solution
{
    private:
        bool canPlaceBalls(int m, int n, vector<int> position, int partition)
        {
            int ball = 1;
            int lastPosition = position[0];

            for (int i = 1; i < n; i++)
            {
                int currPosition = position[i];
                if (currPosition - lastPosition >= partition)
                {
                    ball++;
                    lastPosition = currPosition;
                    
                }
                
                if(ball == m) break;
            }

            return ball == m;
        }
    public:
        int maxDistance(vector<int> &position, int m)
        {
            int n = position.size();
            sort(position.begin(), position.end());
            int st = 0;
            int end = position[n - 1] - position[0];

            int minMagneticForce = 0;
            while (st <= end)
            {
                int mid = st + (end - st) / 2;
                bool canPlace = canPlaceBalls(m, n, position, mid);
                if (canPlace)
                {
                    minMagneticForce = mid;
                    st = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }

            return minMagneticForce;
        }
};