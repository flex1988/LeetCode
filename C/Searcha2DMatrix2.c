bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    if (target < matrix[0][0] || target > matrix[matrixRowSize - 1][matrixColSize - 1])
        return false;
    else {
        for (int i = 0; i < matrixRowSize; i++) {
            for (int j = 0; j < matrixColSize; j++) {
                if (target == matrix[i][j])
                    return true;
            }
        }
        return false;
    }
}
