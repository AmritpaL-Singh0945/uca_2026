class Node{
	int val;
	Node next;

	Node(int val){
		this.val=val;
		this.next=null;
	}
}


public class ReverseLinkedList{

	public static Node reverseList(Node head,Node prev){
		if (head==null) return prev;
		Node Next=head.next;
		head.next=prev;
		return reverseList(Next,head);
	}

	public static void printList(Node head){
		if (head==null) return;

		Node temp=head;
		while (temp!=null){
			System.out.print(temp.val +  "  ");
			temp=temp.next;
		}
		System.out.println();
	}

	public static void main(String[] args){

		Node head=new Node(1);
		Node t=head;

		for (int i=2;i<=5;i++){
			Node temp=new Node(i);
			t.next=temp;
			t=t.next;
		}

		printList(head);
		Node rev=reverseList(head,null);
		printList(rev);


	}
	
}
