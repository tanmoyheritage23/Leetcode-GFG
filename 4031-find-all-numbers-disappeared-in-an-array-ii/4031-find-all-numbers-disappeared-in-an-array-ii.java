class Solution {
    public List<List<Integer>> findDisappearedNumbers(int[] nums, int lower, int upper) {
        Set<Integer> s = new HashSet<>();

        for (int num : nums) {

            s.add(num);

        }

        List<List<Integer>> ans = new ArrayList<>();

        int start = -1;

        for (int i = lower; i <= upper; i++) {

            if (!s.contains(i)) {

                if (start == -1) {

                    start = i;

                }

            } else {

                if (start != -1) {

                    ans.add(Arrays.asList(start, i - 1));

                    start = -1;

                }

            }

        }

        if (start != -1) {

            ans.add(Arrays.asList(start, upper));

        }

        return ans;
    }
}