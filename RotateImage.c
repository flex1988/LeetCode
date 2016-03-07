void rotate(int** matrix, int matrixRowSize, int matrixColSize)
{
    int** ret = malloc(sizeof(int*) * matrixColSize);
    for (int i = matrixColSize - 1; i >= 0; i--) {
        int* tmp = malloc(sizeof(int) * matrixRowSize);
        for (int j = 0; j < matrixRowSize; j++) {
            tmp[j] = matrix[matrixRowSize - j - 1][i];
        }
        ret[i] = tmp;
    }
    memcpy(matrix, ret, sizeof(int*) * matrixColSize);
}
