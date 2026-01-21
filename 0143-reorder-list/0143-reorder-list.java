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
    private ListNode reverse(ListNode head){
        ListNode prev = null;
        while(head != null){
            ListNode temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }
    public void reorderList(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode firstList = head;
        ListNode secondList = reverse(slow.next);
        slow.next = null;

        while(secondList != null){
            ListNode firstTemp = firstList.next;
            firstList.next = secondList;
            ListNode secondTemp = secondList.next;
            secondList.next = firstTemp;
            firstList = firstTemp;
            secondList = secondTemp;
        }
    }
}