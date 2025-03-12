import java.util.HashSet;
import java.util.Set;

public class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        // Use a set to store the unique squared distances.
        Set<Integer> distances = new HashSet<>();
        
        // Calculate the squared distances between all pairs of points.
        distances.add(distanceSquared(p1, p2));
        distances.add(distanceSquared(p1, p3));
        distances.add(distanceSquared(p1, p4));
        distances.add(distanceSquared(p2, p3));
        distances.add(distanceSquared(p2, p4));
        distances.add(distanceSquared(p3, p4));
        
        // For a valid square, there should be exactly 2 distinct distances:
        // - The side (occurs 4 times)
        // - The diagonal (occurs 2 times)
        return distances.size() == 2 && !distances.contains(0);
    }

    private int distanceSquared(int[] p1, int[] p2) {
        // Calculate the squared Euclidean distance.
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
}