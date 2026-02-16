class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        Stack<Integer>st = new Stack<>();
        //Map<Integer,Integer>mp = new HashMap<>();
        int[] result = new int[n];

        for(int i = 0; i < n; i++){
            //Stack Operations:
//Each index is pushed and popped from the stack at most once.
//Push and pop operations are O(1) each.

             while(!st.isEmpty() && temperatures[st.peek()] < temperatures[i]) {
                result[st.peek()] = i - st.peek();
                st.pop();
             }

             st.push(i);
        }

        return result;

    }
}