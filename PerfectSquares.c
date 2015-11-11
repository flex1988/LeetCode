int numSquares(int n)
{
    int result[n + 1];
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            result[0] = 0;
        }
        else {
            int min = 0;
            for (int j = 1; j * j <= i; j++) {
                int t = result[i - j * j] + 1;
                if (min == 0)
                    min = t;
                min = t < min ? t : min;
            }
            result[i] = min;
        }
    }
    return result[n];
}
