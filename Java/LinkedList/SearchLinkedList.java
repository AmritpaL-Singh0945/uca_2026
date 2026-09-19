class Node {
    int val;
    Node next;

    Node(int val) {
        this.val = val;
        this.next = null;
    }
}

public class SearchLinkedList {

    public static boolean isSublist(Node list1, Node list2) {
        if (list1 == null) return true;

        Node start = list2;

        while (start != null) {
            Node p1 = list1;
            Node p2 = start;

            while (p1 != null && p2 != null && p1.val == p2.val) {
                p1 = p1.next;
                p2 = p2.next;
            }

            if (p1 == null) return true;

            start = start.next;
        }

        return false;
    }

    public static void main(String[] args) {
        Node list1 = new Node(1);
        list1.next = new Node(2);
        list1.next.next = new Node(3);

        Node list2 = new Node(5);
        list2.next = new Node(1);
        list2.next.next = new Node(2);
        list2.next.next.next = new Node(3);
        list2.next.next.next.next = new Node(4);

        System.out.println(isSublist(list1, list2) ? "Yes" : "No");
    }
}