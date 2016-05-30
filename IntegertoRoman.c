char* intToRoman(int num)
{
    char* M[4] = { "", "M", "MM", "MMM" };
    char* C[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    char* X[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    char* I[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
    char* ret = (char*)malloc(sizeof(char) * 100);
    strcat(ret, M[num / 1000]);
    strcat(ret, C[(num % 1000) / 100]);
    strcat(ret, X[(num % 100) / 10]);
    strcat(ret, I[num % 10]);
    return ret;
}
