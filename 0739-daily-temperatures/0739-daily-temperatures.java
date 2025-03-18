class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        Stack<Integer>st = new Stack<>();
        //Map<Integer,Integer>mp = new HashMap<>();
        int[] result = new int[n];

        for(int i = n - 1; i >= 0; i--){
             while(!st.isEmpty() && temperatures[st.peek()] <= temperatures[i]) st.pop();
             if(!st.isEmpty()) result[i] = st.peek() - i;

             else result[i] = 0;

             st.push(i);
        }

        return result;

    }
}