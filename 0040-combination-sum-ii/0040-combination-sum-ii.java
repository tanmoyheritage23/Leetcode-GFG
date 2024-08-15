class Solution {
    private void findCombination(int ind, List<Integer>ds, List<List<Integer>>res, int target, int[] candidates){
        if(target == 0){
            res.add(new ArrayList<>(ds));
            return;
        }
        
        for(int i = ind; i < candidates.length; i++){
            
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            ds.add(candidates[i]);
            findCombination(i+1,ds,res,target-candidates[i],candidates);
            ds.remove(ds.size()-1);
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>>res = new ArrayList<>();
        List<Integer>ds = new ArrayList<>();
        findCombination(0,ds,res,target,candidates);
        return res;
    }
}