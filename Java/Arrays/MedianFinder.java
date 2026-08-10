import java.util.PriorityQueue;
import java.util.Collections;

// First, I split the numbers into two piles: a "smaller half" and a "larger half." 
// I set them up so the middle numbers always sit right at the top.
// Whenever a new number arrives, I drop it in and shuffle them to keep both pile sizes balanced
// To find the median, I simply check the top of the piles!

class MedianFinder {
    
    private PriorityQueue<Integer> leftHeap;
    private PriorityQueue<Integer> rightHeap;

    public MedianFinder() {
        leftHeap = new PriorityQueue<>(Collections.reverseOrder());
        rightHeap = new PriorityQueue<>();
    }

    public void insert(int num) {
        leftHeap.offer(num);
        rightHeap.offer(leftHeap.poll());
        
        if (leftHeap.size() < rightHeap.size()) {
            leftHeap.offer(rightHeap.poll());
        }
    }

    public float getMedian() {
        if (leftHeap.size() > rightHeap.size()) {
            return (float) leftHeap.peek();
        }
        
        return (leftHeap.peek() + rightHeap.peek()) / 2.0f;
    }

    public static void main(String[] args) {
        MedianFinder medianFinder = new MedianFinder();
        
        medianFinder.insert(1);
        medianFinder.insert(2);
        System.out.println("Median: " + medianFinder.getMedian());
        
        medianFinder.insert(3);
        System.out.println("Median: " + medianFinder.getMedian());
    }
}