import java.util.*;

class Solution {
    public List<Long> mergeAdjacent(int[] nums) {
        Deque<Long> stack = new ArrayDeque<>();

        for (int num : nums) {
            long current = num;

            while(!stack.isEmpty() && stack.peekLast() == current) {
                stack.pollLast();
                current *= 2;           
               
            }
            stack.addLast(current);
            
        }

        return new ArrayList<>(stack);
    }
}