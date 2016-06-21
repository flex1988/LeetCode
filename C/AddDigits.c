int addDigits(int num)
{
    int result = 0;
    while (num > 0) {
        result += num % 10;
        num = num / 10;
    }
    if (result < 10)
        return result;
    return addDigits(result);
}
