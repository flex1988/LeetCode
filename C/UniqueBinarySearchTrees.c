int numTrees(int n)
{
    int result[n + 1];
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            result[0] = 1;
        }
        else {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += result[j] * result[i - j - 1];
            }
            result[i] = sum;
        }
    }
    return result[n];
}
