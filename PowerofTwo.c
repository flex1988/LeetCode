bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    int a = 0;
    while (n > 1) {
        a = n % 2;
        if (a > 0)
            return false;
        n = n / 2;
    }
    return true;
}
