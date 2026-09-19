class Node {
  int val;
  Node next;

  Node(int val) {
    this.val = val;
    this.next = null;
  }
}

public class IntersectionList {
  public static void printList(Node head) {
    if (head == null)
      return;
    Node temp = head;
    while (temp != null) {
      System.out.print(temp.val + " ");
      temp = temp.next;
    }
    System.out.println();
  }

  public static Node findIntersect(Node a, Node b) {
    Node temp1 = a;
    Node temp2 = b;

    Node res = new Node(Integer.MAX_VALUE);
    Node temp3 = res;

    while (temp1 != null && temp2 != null) {
      if (temp1.val == temp2.val) {
        temp3.next = new Node(temp1.val);
        temp3 = temp3.next;

        temp1 = temp1.next;
        temp2 = temp2.next;
      } else if (temp1.val < temp2.val) {
        temp1 = temp1.next;
      } else {
        temp2 = temp2.next;
      }
    }

    return res.next;
  }
  public static void main(String[] args) {
    int[] a = new int[] {1, 2, 2, 3, 4};
    int[] b = new int[] {2, 2, 2, 4};

    Node list1 = new Node(a[0]);
    Node list2 = new Node(b[0]);

    Node temp1 = list1;
    Node temp2 = list2;

    for (int i = 1; i < a.length; i++) {
      Node t = new Node(a[i]);
      temp1.next = t;
      temp1 = temp1.next;
    }

    for (int j = 1; j < b.length; j++) {
      Node t = new Node(b[j]);
      temp2.next = t;
      temp2 = temp2.next;
    }

    printList(list1);
    printList(list2);

    Node res = findIntersect(list1, list2);

    printList(res);
  }
}
