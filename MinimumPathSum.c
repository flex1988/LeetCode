int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
    int result[gridRowSize][gridColSize];

    result[0][0] = grid[0][0];
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (i == 0 && j > 0)
                result[i][j] = result[i][j - 1] + grid[i][j];
            else if (i > 0 && j == 0) {
                result[i][j] = result[i - 1][j] + grid[i][j];
            }
            else if (i > 0 && j > 0) {
                result[i][j] = result[i - 1][j] > result[i][j - 1] ? result[i][j - 1] + grid[i][j] : result[i - 1][j] + grid[i][j];
            }
        }
    }
    return result[gridRowSize - 1][gridColSize - 1];
}
