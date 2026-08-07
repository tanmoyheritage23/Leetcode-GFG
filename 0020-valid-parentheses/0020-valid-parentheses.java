class Solution {
    public boolean isValid(String s) {
        Map<Character,Character> parenthesis = new HashMap<>();
        parenthesis.put(')','(');
        parenthesis.put('}','{');
        parenthesis.put(']','[');

        Stack<Character>st = new Stack<>();
        int i = 0;
        int n = s.length();

        while( i < n){
            char ch = s.charAt(i);
            if(ch == ')' || ch == '}' || ch == ']'){
                if(!st.isEmpty() && st.peek() == parenthesis.get(ch)){
                    st.pop();
                }
                else return false;
            }
            else st.push(ch);
            i++;
        }

        return st.isEmpty();

    }
}