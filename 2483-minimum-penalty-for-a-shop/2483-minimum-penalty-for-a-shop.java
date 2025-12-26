class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length();

        int[] prefixSumYes = new int[n];
        int[] prefixSumNo = new int[n];

        /* intuition: for i = 0 -> n i.e. for each closing hour we will check beforePenalty(penalty from to 0 -> i-1) and afterPenalty(from i -> n-1)

        beforePenalty => count of "N" i.e. form 0 -> i-1 th hour shop is open but customer is not coming. So there should be a penalty. 

        afterPenalty => count of "Y" from i -> n-1 th hour shop is closed but customer is coming. So there should also be a penalty.
        */

        prefixSumYes[0] = customers.charAt(0) == 'Y' ? 1 : 0;
        prefixSumNo[0] = customers.charAt(0) == 'N' ? 1 : 0;

        for(int i = 1; i < n; i++){
            prefixSumYes[i] = (customers.charAt(i) == 'Y' ? 1 : 0) + prefixSumYes[i-1];
            prefixSumNo[i] = (customers.charAt(i) == 'N' ? 1 : 0) + prefixSumNo[i-1];
        }

        int minPenalty = Integer.MAX_VALUE; int minPenaltyHour = -1;
        
        for(int i = 0; i <= n; i++){

            int beforePenalty = i > 0 ? prefixSumNo[i-1] : 0;
            int afterPenalty =  i < n ? (prefixSumYes[n-1] - (i > 0 ? prefixSumYes[i-1] : 0)) : 0;
            int totalPenalty = beforePenalty + afterPenalty;

            if(totalPenalty < minPenalty){
                minPenalty = totalPenalty;
                minPenaltyHour = i;
            }
        }

        return minPenaltyHour;
    }
}