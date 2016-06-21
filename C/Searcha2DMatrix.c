bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    for (int i = 0; i < matrixRowSize; i++) {
        if (target >= matrix[i][0] && target <= matrix[i][matrixColSize - 1]) {
            for (int j = 0; j < matrixColSize; j++) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
    }
    return false;
}
