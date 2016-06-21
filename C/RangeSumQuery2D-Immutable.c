struct NumMatrix {
    int** matrix;
    int matrixRowSize;
    int matrixColSize;
};

/** Initialize your data structure here. */
struct NumMatrix* NumMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize)
{
    struct NumMatrix* num = malloc(sizeof(struct NumMatrix));
    num->matrixRowSize = matrixRowSize;
    num->matrixColSize = matrixColSize;
    num->matrix = matrix;
    for (int i = 0; i < matrixRowSize; i++) {
        int t = 0;
        for (int j = 0; j < matrixColSize; j++) {
            t += num->matrix[i][j];
            num->matrix[i][j] = i == 0 ? t : num->matrix[i - 1][j] + t;
            // printf("%d %d %d\n",i,j,num->matrix[i][j]);
        }
    }
    return num;
}

int sumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2, int col2)
{
    if (row1 == 0 && col1 == 0)
        return numMatrix->matrix[row2][col2];
    if (row1 == 0) {
        return numMatrix->matrix[row2][col2] - numMatrix->matrix[row2][col1 - 1];
    }
    if (col1 == 0) {
        return numMatrix->matrix[row2][col2] - numMatrix->matrix[row1 - 1][col2];
    }
    int t = sumRegion(numMatrix, 0, 0, row1 - 1, col1 - 1);
    return numMatrix->matrix[row2][col2] - numMatrix->matrix[row2][col1 - 1] - numMatrix->matrix[row1 - 1][col2] + t;
}

/** Deallocates memory previously allocated for the data structure. */
void NumMatrixFree(struct NumMatrix* numMatrix) { free(numMatrix); }

// Your NumMatrix object will be instantiated and called as such:
// struct NumMatrix* numMatrix = NumMatrixCreate(matrix, matrixRowSize, matrixColSize);
// sumRegion(numMatrix, 0, 1, 2, 3);
// sumRegion(numMatrix, 1, 2, 3, 4);
// NumMatrixFree(numMatrix);
