class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagramMap = new HashMap<>();

        
            
            for(String word: strs){
                char[] ch = word.toCharArray();
                int[] charCount = new int[26];
                for(char c: ch){
                    charCount[c - 'a']++;
                }

                StringBuilder keyBuilder = new StringBuilder();
                for(int count: charCount){
                    keyBuilder.append("#");
                    keyBuilder.append(count);
                }

                String key = new String(keyBuilder);

               if(!anagramMap.containsKey(key)){
                    anagramMap.put(key, new ArrayList<>());
                }

                anagramMap.get(key).add(word);
                
            }

            return new ArrayList<>(anagramMap.values());
        
    }
}