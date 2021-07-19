package leetcode;

public class leetcode19 {

    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head.next == null)
            return null;

        ListNode front = head;
        ListNode end = head;
        for(int i = 0 ; i < n;i++)
            end = end.next;

        if(end == null)
            return head.next;

        while(end.next != null){
            front = front.next;
            end = end.next;
        }

        front.next = front.next.next;
        return head;
    }
}
