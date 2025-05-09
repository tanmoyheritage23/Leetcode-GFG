class Solution {
    private Set<Integer> cols = new HashSet<>();
    private Set<Integer> posDiag = new HashSet<>(); // r + c
    private Set<Integer> negDiag = new HashSet<>(); // r - c

    private void backtrack(int row, int n, List<String> board, List<List<String>> result) {
        if (row == n) {
            result.add(new ArrayList<>(board));
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols.contains(col) || posDiag.contains(row + col) || negDiag.contains(row - col)) {
                continue;
            }

            // Place the queen
            char[] rowArray = new char[n];
            Arrays.fill(rowArray, '.');
            rowArray[col] = 'Q';
            board.add(new String(rowArray));
            cols.add(col);
            posDiag.add(row + col);
            negDiag.add(row - col);

            // Move to the next row
            backtrack(row + 1, n, board, result);

            // Backtrack
            board.remove(board.size() - 1);
            cols.remove(col);
            posDiag.remove(row + col);
            negDiag.remove(row - col);
        }
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        backtrack(0, n, new ArrayList<>(), result);
        return result;
    }
}