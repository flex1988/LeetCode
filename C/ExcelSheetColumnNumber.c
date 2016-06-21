int titleToNumber(char* s)
{
    int len = strlen(s);
    int sum = 0;
    for (int i = len - 1; i >= 0; i--) {
        sum += (s[i] - 'A' + 1) * pow(26, len - i - 1);
    }
    return sum;
}
