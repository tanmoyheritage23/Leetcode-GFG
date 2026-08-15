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
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode prev = dummy, first = head;

        prev.next = first;

        while(first != null && first.next != null){
            ListNode second = first.next;

            prev.next = second;
            first.next = second.next;
            second.next = first;

            prev = first;
            first = first.next;
        }

        return dummy.next;
    }
}