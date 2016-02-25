int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
    int arr[101][101] = { 0 };
    for (int i = 1; i < obstacleGridRowSize + 1; i++) {
        for (int j = 1; j < obstacleGridColSize + 1; j++) {
            if (i == 1 && j == 1)
                arr[i][j] = obstacleGrid[i - 1][j - 1] == 1 ? 0 : 1;
            else if (obstacleGrid[i - 1][j - 1] == 0)
                arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }
    return arr[obstacleGridRowSize][obstacleGridColSize];
}
