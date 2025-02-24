/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
       /* string first = "";
        string second = "";
        
        while(l1 != NULL){
            
            first += l1 -> val;
            l1 = l1 -> next;
        }
        
        while(l2 != NULL){
            
            second += l2 -> val;
            l2 = l2 -> next;
        }
        
        reverse(first.begin(),first.end());
        reverse(second.begin(),second.end());
        
        int final = stoi(first) + stoi(second);
        int add = 0;
        ListNode* head = new ListNode(0); ListNode* curr = head;
        while(final > 0){
            
            add = final % 10;
            final = final / 10;
            ListNode* node = new ListNode(add);
            curr -> next = node;
            curr = curr -> next;
        }
        
        return head -> next;
        */
        
        ListNode* l3 = new ListNode(0); ListNode* head = l3; 
        int carry = 0;
        
        while(l1 && l2){
            
            int value = l1 -> val + l2 -> val + carry;
            carry = value / 10;
            l3 -> next = new ListNode(value % 10);
            l3 = l3 -> next;
            l1 = l1 ->next;
            l2 = l2 -> next;
            
        }
        
        while(l1){
            
            int value = l1 -> val + carry;
            carry = value / 10;
            l3 -> next = new ListNode(value % 10);
            l3 = l3 -> next;
            l1 = l1 ->next;
            
        }
        
        while(l2){
            
            int value = l2 -> val + carry;
            carry = value / 10;
            l3 -> next = new ListNode(value % 10);
            l3 = l3 -> next;
            l2 = l2 -> next;
            
        }
        
        if(carry){
            
            l3 -> next = new ListNode(carry);
        }
        
        return head -> next;
    }
};