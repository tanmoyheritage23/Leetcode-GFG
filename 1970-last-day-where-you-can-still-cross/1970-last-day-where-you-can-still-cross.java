class Solution {

    int[] parent;

    public int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    public void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) parent[pa] = pb;
    }

    public int latestDayToCross(int row, int col, int[][] cells) {

        int total = row * col;
        int TOP = total;
        int BOTTOM = total + 1;

        parent = new int[total + 2];
        for (int i = 0; i < total + 2; i++) parent[i] = i;

        boolean[][] land = new boolean[row][col];

        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = cells.length - 1; i >= 0; i--) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            land[r][c] = true;

            int id = r * col + c;

            if (r == 0) union(id, TOP);
            if (r == row - 1) union(id, BOTTOM);

            for (int[] d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col && land[nr][nc]) {
                    union(id, nr * col + nc);
                }
            }

            if (find(TOP) == find(BOTTOM)) return i;
        }

        return 0;
    }
}