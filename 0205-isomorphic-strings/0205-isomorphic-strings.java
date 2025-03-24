class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length() != t.length()) return false;

        Map<Character, Character>mapST = new HashMap<>();
        Map<Character, Character>mapTS = new HashMap<>();

        for(int i = 0; i < s.length(); i++){
            char charS = s.charAt(i);
            char charT = t.charAt(i);

            if(mapST.containsKey(charS)){
                if(mapST.get(charS) != charT) return false;
            }else{
                mapST.put(charS, charT);
            }

            if(mapTS.containsKey(charT)){
                if(mapTS.get(charT) != charS) return false;
            }else{
                mapTS.put(charT, charS);
            }
        }

        return true;
    }
}