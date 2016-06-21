bool isHappy(int n)
{
    int m = n;
    int* map = malloc(sizeof(int) * 1000);
    while (m) {
        int sum = 0;
        while (m) {
            int t = m % 10;
            sum += t * t;
            m = m / 10;
        }
        if (sum == 1)
            return true;
        m = sum;
        if (map[sum])
            return false;
        map[sum] = 1;
    }
    return false;
}
