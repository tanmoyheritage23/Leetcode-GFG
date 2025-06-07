class Solution {
    public int calculate(String s) {
        if(s==null || s.isEmpty()) return 0;
        int n = s.length();
        int currNum = 0;
        char op = '+';
        Stack<Integer>st = new Stack<>();

        for(int i = 0; i < n; i++){
            char currChar = s.charAt(i);
            if(Character.isDigit(currChar)){
                currNum = (currNum * 10) + (currChar - '0');
            }
            if(!Character.isDigit(currChar) && !Character.isWhitespace(currChar) || i == n - 1){
                if(op == '+'){
                    st.add(currNum);
                }
                if(op == '-'){
                    st.add(-currNum);
                }
                if(op == '*'){
                    st.add(st.pop() * currNum);
                }
                if(op == '/'){
                    st.add(st.pop() / currNum);
                }
                op = currChar;
                currNum = 0;
            }
        }

        int result = 0;
        while(!st.isEmpty()){
            result += st.pop();
        }

        return result;
    }
}