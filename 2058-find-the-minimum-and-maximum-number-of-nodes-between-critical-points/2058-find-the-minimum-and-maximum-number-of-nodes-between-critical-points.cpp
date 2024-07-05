/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        vector<int> nodesBetweenCriticalPoints(ListNode *head)
        {
            ListNode *prev = NULL;
            ListNode *nxt = NULL;
            ListNode *curr = head;

            int currindex = 1;
            vector<int> dist;
            int minDist = INT_MAX, maxDist = -1;

            while (curr->next != NULL)
            {
                if (prev != NULL || nxt != NULL)
                {
                    if ((curr->val > nxt->val && curr->val > prev->val) || (curr->val < prev->val && curr->val < nxt->val))
                    {
                        if(dist.size() > 0){
                            minDist = min(minDist,currindex - dist.back());
                        }
                        dist.push_back(currindex);
                    }
                }

                prev = curr;
                curr = curr->next;
                nxt = curr->next;

                currindex++;
            }

            if (dist.size()) maxDist = dist[dist.size() - 1] - dist[0];

            if(minDist ==INT_MAX || maxDist == -1){
                return {-1,-1};
            }
            else return {minDist,maxDist};
        }
};