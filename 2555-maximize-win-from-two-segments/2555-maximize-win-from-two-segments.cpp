class Solution
{
    public:
       	// basically for ant index i, (0,i) will give me one segment out of all segments possible
       	//in this range (0,i) in such a way that it will give me max. prize. Similarly (i+1,n-1)
       	// will give me one segment out of all segments possible in this range (i+1,n-1) in such
       	// way that it will give me max.prize. So adding up their values will give me max.prize
       	// possible for any index i and i have to do that for every index. out of thsese whichever 
       	// will give maximum answer, would be my answer.
        int maximizeWin(vector<int> &prizePositions, int k)
        {
            int n = prizePositions.size();
            vector<int> pref(n), suff(n);

           	// Find maximum count of prize for(0,i). It can be[1,3], [2,4], [3,5]...out of these
           	// segments whichever will give me max count, i will choose it. For this example it 
           	// is[1,3]

            int count = 0, maxCount = 0;
            int st = 0;
            int end = prizePositions[0] + k;

            for (int i = 0; i < n; i++)
            {
                int curr = prizePositions[i];

                if (curr <= end) count++;
                else
                {
                   	// i will keep contracting my window until my curr is in range or so to say
                   	// find a new range
                    while (curr > end)
                    {
                        st++;
                        end = prizePositions[st] + k;
                        count--;
                    }

                    count++;
                }
                maxCount = max(maxCount, count);
                pref[i] = maxCount;	// store the max count for (0,i);
            }

            count = 0, maxCount = 0;
            st = n - 1;
            end = prizePositions[n - 1] - k;

            for (int i = n - 1; i >= 0; i--)
            {
                int curr = prizePositions[i];

                if (curr >= end) count++;
                else
                {
                   	// i will keep contracting my window until my curr is in range or so to say
                   	// find a new range
                    while (curr < end)
                    {
                        st--;
                        end = prizePositions[st] - k;
                        count--;
                    }

                    count++;
                }
                maxCount = max(maxCount, count);
                suff[i] = maxCount;	// store the max count for (i,n-1)
            }

            int maxPrize = 0;
            for (int i = 0; i < n; i++)
            {
                int prize = pref[i];
                if (i + 1 < n) prize += suff[i + 1];
                maxPrize = max(maxPrize, prize);
            }
            return maxPrize;
        }
};