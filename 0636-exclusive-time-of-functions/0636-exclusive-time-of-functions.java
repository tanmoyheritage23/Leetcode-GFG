class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Stack<Integer> st = new Stack<>();
        String[] s = logs.get(0).split(":");
        int[] res = new int[n];

        st.push(Integer.parseInt(s[0]));
        int i = 1, prevTime = Integer.parseInt(s[2]);

        while(i < logs.size()){
            s = logs.get(i).split(":");
            if(s[1].equals("start")){
                if(!st.isEmpty()) res[st.peek()] += Integer.parseInt(s[2]) - prevTime;
                st.push(Integer.parseInt(s[0]));
                prevTime = Integer.parseInt(s[2]);
            }else{
                res[st.peek()] += Integer.parseInt(s[2]) - prevTime + 1;
                st.pop();
                prevTime = Integer.parseInt(s[2]) + 1;
            }
            i++;
        }
        return res;
    }
}