class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        
        Stack<Integer>st = new Stack<>();

        int ans = 0;

        for(int num: nums){
            while(!st.isEmpty() && st.peek() > num){
                st.pop();
                ans++;

            }

            if(!st.isEmpty() && st.peek() == num) continue;

            if(num != 0) st.add(num);
        }

        ans += st.size();

        return ans;

        
    }
}