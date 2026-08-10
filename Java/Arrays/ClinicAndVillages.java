import java.util.PriorityQueue;

// First, I gave one clinic to every village.
// Next, I put them in a priority list that always keeps the most crowded village at the very top. 
// I handed out my leftover clinics one by one to the top village, updating their patient load each time. 
// Finally, the top village's load gave me the answer!

public class ClinicAndVillages {

    public static double getMinMaxLoad(int n, int[] population, int k) {
        PriorityQueue<double[]> maxHeap = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));

        for (int p : population) {
            maxHeap.offer(new double[]{ (double) p, (double) p, 1.0 });
        }

        int remainingClinics = k - n;

        while (remainingClinics > 0) {
            double[] maxLoadVillage = maxHeap.poll();
            
            maxLoadVillage[2] += 1.0;
            maxLoadVillage[0] = maxLoadVillage[1] / maxLoadVillage[2];
            
            maxHeap.offer(maxLoadVillage);
            remainingClinics--;
        }

        double minMaxLoad = maxHeap.peek()[0];
        
        return Math.round(minMaxLoad * 100.0) / 100.0;
    }

    public static void main(String[] args) {
        int n = 3;
        int[] population = {200, 20, 50};
        int k = 5;
        
        System.out.println(getMinMaxLoad(n, population, k));
    }
}