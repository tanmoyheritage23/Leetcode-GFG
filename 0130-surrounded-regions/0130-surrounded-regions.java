class Solution {
    public void solve(char[][] board) {
        if (board == null || board.length == 0)
            return;

        int rows = board.length;
        int cols = board[0].length;

        Queue<int[]> queue = new LinkedList<>();

        // Add all boundary 'O's to the queue and print their coordinates
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') {
                System.out.println(i + "-" + 0);
                queue.offer(new int[] { i, 0 });
            }
            if (board[i][cols - 1] == 'O') {
                System.out.println(i + "-" + (cols - 1));
                queue.offer(new int[] { i, cols - 1 });
            }
        }
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') {
                System.out.println(0 + "-" + j);
                queue.offer(new int[] { 0, j });
            }
            if (board[rows - 1][j] == 'O') {
                System.out.println((rows - 1) + "-" + j);
                queue.offer(new int[] { rows - 1, j });
            }
        }

        // Directions for moving in the matrix (up, down, left, right)
        int[][] directions = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

        // Perform BFS
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int x = cell[0], y = cell[1];

            if (board[x][y] != 'O')
                continue;

            board[x][y] = '#'; // Mark the cell as visited

            for (int[] dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                // Ensure coordinates are within bounds
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && board[newX][newY] == 'O') {
                    System.out.println(newX + "-" + newY);
                    queue.offer(new int[] { newX, newY });
                }
            }
        }

        // Flip the cells
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X'; // Flip unvisited 'O's to 'X'
                else if (board[i][j] == '#')
                    board[i][j] = 'O'; // Restore visited '#' back to 'O'
            }
        }
    }
}