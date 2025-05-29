/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
       ListNode dummy = new ListNode(-1); 
       dummy.next = head;
       
       ListNode LeftPrev = dummy;
       ListNode curr = head;
       for(int i = 0; i < left - 1; i++){
           LeftPrev = curr;
           curr = curr.next;
       }

       ListNode prev = null;

       for(int i = 0; i < right - left + 1; i++){
          ListNode temp = curr.next;
          curr.next = prev;
          prev = curr;
          curr = temp;
       }

       LeftPrev.next.next = curr;
       LeftPrev.next = prev;

       return dummy.next;
    }
}