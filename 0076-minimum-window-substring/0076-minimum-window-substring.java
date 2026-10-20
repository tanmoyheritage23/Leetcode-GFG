class Solution {
    public String minWindow(String s, String t) {
        if(s.length() == 0 || t.length() == 0 || s.length() < t.length()) return "";
        
       int[] v = new int[128];
                                               // Youtube link : https://youtu.be/rw660m-QLDo
       for(int i = 0; i < t.length(); i++){
           
           v[t.charAt(i)]++;
       }
        
        int st = 0; int end = 0; int ans_st = 0; int mini = Integer.MAX_VALUE; int count = 0;
        
        while(end < s.length()){
            
            if(v[s.charAt(end)] > 0) count++;
            v[s.charAt(end)]--;
            
            while(count == t.length()){
                
                if(mini > end - st + 1){
                    
                    mini = end - st + 1;
                    ans_st = st;
                    
                }
                
                v[s.charAt(st)]++;
                if(v[s.charAt(st)] > 0) count--;
                st++;
                
            }
            
            end++;
        }
        
        if(mini == Integer.MAX_VALUE) return "";
        return s.substring(ans_st,ans_st+mini);
    }
}