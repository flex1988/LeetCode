int climbStairs(int n)
{
    int res[n];
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else {

        res[0] = 1;
        res[1] = 2;

        for (int i = 2; i < n; i++) {
            res[i] = res[i - 2] + res[i - 1];
        }
    }

    return res[n - 1];
}
