class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] word = s.split(" ");
        int n = pattern.length();
        int m = word.length;

        if(n != m) return false;

        Map<Character, String>charToWord = new HashMap<>();

        for(int i = 0; i < n; i++){
            Character ch = pattern.charAt(i);
            if(charToWord.containsKey(ch)){
                if(!charToWord.get(ch).equals(word[i])) return false;
            }else if(charToWord.containsValue(word[i])){
                return false;
            }else{
                charToWord.put(ch,word[i]);
            }
        }

        return true;
    }
}