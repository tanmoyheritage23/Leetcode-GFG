class Solution {

    private void findCombination(int ind, List<Integer> ds, List<List<Integer>> res, int target, int[] candidates) {
        if (ind == candidates.length) {
            if (target == 0) {
                res.add(new ArrayList<>(ds));
            }
            return;
        }

        if (candidates[ind] <= target) {
            ds.add(candidates[ind]);
            findCombination(ind, ds, res, target - candidates[ind], candidates);
            ds.remove(ds.size() - 1);
        }

        findCombination(ind + 1, ds, res, target, candidates);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        findCombination(0, ds, res, target, candidates);
        return res;
    }
}
