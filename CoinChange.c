int coinChange(int* coins, int coinsSize, int amount)
{
    int ret[coinsSize][amount + 1];
    for (int i = 0; i < coinsSize; i++) {
        for (int j = 0; j < amount + 1; j++) {
            if (j == 0)
                ret[i][j] = 0;
            else {
                if (i == 0) {
                    if (coins[i] > j)
                        ret[i][j] = -1;
                    else if (coins[i] == j)
                        ret[i][j] = 1;
                    else {

                        ret[i][j] = ret[i][j - coins[i]] == -1 ? -1 : (ret[i][j - coins[i]] + 1);
                    }
                }
                else if (j < coins[i])
                    ret[i][j] = ret[i - 1][j];
                else if (j == coins[i])
                    ret[i][j] = 1;
                else {
                    if (ret[i - 1][j] == -1 && ret[i][j - coins[i]] != -1)
                        ret[i][j] = ret[i][j - coins[i]] + 1;
                    else if (ret[i][j - coins[i]] == -1 && ret[i - 1][j] != -1)
                        ret[i][j] = ret[i - 1][j];
                    else
                        ret[i][j] = ret[i - 1][j] > (ret[i][j - coins[i]] + 1) ? (ret[i][j - coins[i]] + 1) : (ret[i - 1][j]);
                }
            }
        }
    }
    return ret[coinsSize - 1][amount];
}
