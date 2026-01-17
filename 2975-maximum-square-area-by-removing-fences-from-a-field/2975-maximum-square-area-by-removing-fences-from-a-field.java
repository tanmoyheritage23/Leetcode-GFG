class Solution {

    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        Set<Integer> widths = getEdges(hFences, m);
        Set<Integer> heights = getEdges(vFences, n);

        long res = 0;
        for (int e : widths) {
            if (heights.contains(e)) {
                res = Math.max(res, e);
            }
        }

        if (res == 0) {
            return -1;
        } else {
            return (int) ((res * res) % 1000000007);
        }
    }

    private Set<Integer> getEdges(int[] fences, int border) {
        Set<Integer> set = new HashSet<>();
        List<Integer> list = new ArrayList<>();

        for (int fence : fences) {
            list.add(fence);
        }

        list.add(1);
        list.add(border);

        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                set.add(Math.abs(list.get(j) - list.get(i)));
            }
        }

        return set;
    }
}