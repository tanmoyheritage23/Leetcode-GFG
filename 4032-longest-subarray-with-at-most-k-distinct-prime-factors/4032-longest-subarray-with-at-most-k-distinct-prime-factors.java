class Solution {
    public int longestSubarray(int[] nums, int k) {
        int maxi = Arrays.stream(nums).max().getAsInt();
        Map<Integer,List<Integer>> primeFactors = new HashMap<>();
        for(int i = 2; i <= maxi; i++){
            int n = i;
            for(int j = 2; j*j <= n; j++){
                if(n%j == 0){
                    primeFactors.computeIfAbsent(i, x -> new ArrayList<>()).add(j);
                }
                while(n%j == 0){
                    n/=j;
                }
            }
            if(n > 1) {
                primeFactors.computeIfAbsent(i, x -> new ArrayList<>()).add(n);
            }
        }

        int start = 0, end = 0;
        int n = nums.length;
        int maxLength = 0;
        
        Map<Integer,Integer> distinctFreq = new HashMap<>();
        while(end < n){
            int num = nums[end];
            for(int primeFactor: primeFactors.get(num)){
                distinctFreq.put(primeFactor,distinctFreq.getOrDefault(primeFactor,0)+1);
            }
            while(distinctFreq.size() > k){
                int remove = nums[start];
                for(int primeFactor: primeFactors.get(remove)){
                    distinctFreq.put(primeFactor,distinctFreq.get(primeFactor)-1);
                    if(distinctFreq.get(primeFactor) == 0){
                        distinctFreq.remove(primeFactor);
                    }
                }
                start++;
                
            }
            maxLength = Math.max(maxLength, end - start + 1);
            end++;
            
        }

        return maxLength;
    }
}