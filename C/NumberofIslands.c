int find(int* pre, int x);
void join(int* pre, int x, int y);

int numIslands(char** grid, int gridRowSize, int gridColSize)
{
    int* pres = calloc(gridRowSize * gridColSize + 1, sizeof(int));
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (grid[i][j] == '1') {
                if ((j > 0 && grid[i][j - 1] == '1') || (i > 0 && grid[i - 1][j] == '1')) {
                    if (j > 0 && grid[i][j - 1] == '1')
                        join(pres, i * gridColSize + j, i * gridColSize + j + 1);
                    if (i > 0 && grid[i - 1][j] == '1')
                        join(pres, (i - 1) * gridColSize + j + 1, i * gridColSize + j + 1);
                }
                else
                    pres[i * gridColSize + j + 1] = i * gridColSize + j + 1;
            }
        }
    }
    int count = 0;
    for (int i = 1; i < gridRowSize * gridColSize + 1; i++) {
        if (pres[i] == i)
            count++;
    }
    return count;
}

int find(int* pre, int x)
{
    int r = x;
    while (pre[r] != r && pre[r] != 0)
        r = pre[r];
    return r;
}

void join(int* pre, int x, int y)
{
    int fx = find(pre, x);
    int fy = find(pre, y);
    if (fx != fy)
        pre[fy] = fx;
}
