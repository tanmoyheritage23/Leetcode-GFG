class Solution
{
    public:
        int countStudents(vector<int> &students, vector<int> &sandwiches)
        {
            deque<int> studentsQueue;
            queue<int> q;
            for (int s: sandwiches)
            {
                q.push(s);
            }
            for (int s: students)
            {
                studentsQueue.push_back(s);
            }
            int swap = 0;
            while (swap != studentsQueue.size())
            {
                if (studentsQueue.front() == q.front())
                {
                    studentsQueue.pop_front();
                    q.pop();
                    swap = 0;
                }
                else
                {
                    int temp = studentsQueue.front();
                    studentsQueue.pop_front();
                    studentsQueue.push_back(temp);
                    swap++;
                }
            }

            return (int)q.size();
        }
};

