bool isPowerOfThree(int n)
{
    if (n == 0)
        return false;
    if (n == 1)
        return true;
    if (n == 3)
        return true;
    int t = n % 3;
    if (t != 0)
        return false;
    else
        return isPowerOfThree(n / 3);
}
