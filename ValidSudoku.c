bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
    int* htable = calloc(9, sizeof(int));
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] != '.') {
                if (htable[board[i][j] - '1'] > 0)
                    return false;
                htable[board[i][j] - '1'] = 1;
            }
        }
        free(htable);
        htable = calloc(9, sizeof(int));
    }
    for (int i = 0; i < boardColSize; i++) {
        for (int j = 0; j < boardRowSize; j++) {
            if (board[j][i] != '.') {
                if (htable[board[j][i] - '1'] > 0)
                    return false;
                htable[board[j][i] - '1'] = 1;
            }
        }
        free(htable);
        htable = calloc(9, sizeof(int));
    }

    int boxCol = boardColSize / 3;
    int boxRow = boardRowSize / 3;

    for (int i = 0; i < boxRow; i++) {
        for (int j = 0; j < boxCol; j++) {

            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (board[i * 3 + x][j * 3 + y] != '.') {
                        if (htable[board[i * 3 + x][j * 3 + y] - '1'] > 0)
                            return false;
                        htable[board[i * 3 + x][j * 3 + y] - '1'] = 1;
                    }
                }
            }
            free(htable);
            htable = calloc(9, sizeof(int));
        }
    }

    return true;
}
