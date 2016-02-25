int reverse(int x)
{
    int* array = calloc(100, sizeof(int));
    int isPositive = x < 0 ? 1 : 0;
    if (isPositive) {
        x = -x;
    }

    int index = 0;

    while (x) {
        array[index++] = x % 10;
        x = x / 10;
    }
    int ret = 0;
    int t = 0;
    while (t < index) {
        if (ret > 214748364 || ret < -214748363)
            return 0;
        ret = ret * 10 + array[t++];
    }

    return ret * (isPositive ? -1 : 1);
}
