int myAtoi(char* str)
{
    int len = strlen(str);
    int isPositive = 0;
    int i = 0;
    int flag = 0;

    int ret = 0;
    for (; i < len; i++) {
        if (str[i] == ' ') {
            if (flag)
                break;
            if (isPositive)
                break;
            continue;
        };
        if (str[i] == '-') {
            if (isPositive != 0)
                return 0;
            isPositive = -1;
            continue;
        }
        if (str[i] == '+') {
            if (isPositive != 0)
                return 0;
            isPositive = 1;
            continue;
        }
        int t = str[i] - '0';
        if (t > 9 || t < 0)
            break;
        flag = 1;
        if ((isPositive != -1) && (ret > 214748364 || (ret == 214748364 && t > 7)))
            return 2147483647;
        if ((isPositive == -1) && (ret > 214748364 || (ret == 214748364 && t > 8)))
            return -2147483648;
        ret = ret * 10 + t;
    }
    return ret * (isPositive ? isPositive : 1);
}
