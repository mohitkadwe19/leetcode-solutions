class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

class Solution {
    // Function to pairwise swap elements of a linked list.
    // It should returns head of the modified list
    public Node pairwiseSwap(Node head)
    {
         Node curr=head;
        Node ans=head.next; 
       
        if(curr.next==null){
            return curr;
        }
        
        if(curr.next.next==null){
            Node temp=curr.next;
            curr.next.next=curr;
            curr.next=null;
            return temp;
        }
        
        
        Node temp2=curr.next.next;
        curr.next.next=curr;
        curr.next=temp2;
        curr.next=pairwiseSwap(temp2);
        return ans;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);

        Node newHead = sol.pairwiseSwap(head);
        while(newHead != null) {
            System.out.print(newHead.data + " ");
            newHead = newHead.next;
        }
    }
}