/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
    int* ret = malloc(sizeof(int) * matrixRowSize * matrixColSize);
    int index = 0;
    int min = matrixRowSize > matrixColSize ? matrixColSize : matrixRowSize;
    int length = min % 2 == 0 ? min / 2 : (min / 2 + 1);

    for (int i = 0; i < length; i++) {

        for (int j = i; j < matrixColSize - i; j++) {
            ret[index++] = matrix[i][j];
        }

        for (int j = i + 1; j < matrixRowSize - i - 1; j++) {
            ret[index++] = matrix[j][matrixColSize - i - 1];
        }

        if (matrixRowSize - i - 1 > i) {
            for (int j = matrixColSize - i - 1; j >= i; j--) {
                ret[index++] = matrix[matrixRowSize - i - 1][j];
            }
        }

        if (i < matrixColSize - i - 1) {
            for (int j = matrixRowSize - i - 2; j > i; j--) {
                ret[index++] = matrix[j][i];
            }
        }
    }
    return ret;
}
