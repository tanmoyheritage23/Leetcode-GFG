class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        int n = words.length;
        if(words[startIndex].equals(target)) return 0;

        int shortestDistance = Integer.MAX_VALUE;

        int nextIndex = (startIndex + 1) % n;
        while(nextIndex != startIndex){
            if(words[nextIndex].equals(target)){
                if(nextIndex < startIndex){
                    shortestDistance = Math.min(shortestDistance, n - startIndex + nextIndex);
                }
                else{
                    shortestDistance = Math.min(shortestDistance, nextIndex - startIndex);
                }
            }
            nextIndex = (nextIndex + 1) % n;
        }

        int prevIndex = (startIndex - 1 + n) % n;
        while(prevIndex != startIndex){
            if(words[prevIndex].equals(target)){
                if(prevIndex > startIndex){
                    shortestDistance = Math.min(shortestDistance, n - prevIndex + startIndex);
                }
                else{
                    shortestDistance = Math.min(shortestDistance, startIndex - prevIndex);
                }
            }
            prevIndex = (prevIndex - 1 + n) % n;
        }


        return shortestDistance == Integer.MAX_VALUE ? -1 : shortestDistance;

        


    }
}