class Solution {
    public String decodeString(String s) {
        Stack<Character>st = new Stack<>();

        for(char c: s.toCharArray()){
            if(c != ']'){
                st.add(c);
            }else{
                StringBuilder sb = new StringBuilder();
                while(st.peek() != '['){
                    sb.insert(0,st.pop());

                }
                st.pop();
                int k = 0;
                int base = 1;
                while(!st.isEmpty() && Character.isDigit(st.peek())){
                    int digit = st.pop() - '0';
                    k += base * digit;
                    base *= 10;
                }
                String decoded = sb.toString().repeat(k);
                for(char ch: decoded.toCharArray()){
                    st.push(ch);
                }
            }
        }

        StringBuilder result = new StringBuilder();
        for(char c: st){
            result.append(c);
        }

        return result.toString();
    }
}