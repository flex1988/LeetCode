char* convert(char* s, int numRows)
{
    if (numRows == 1)
        return s;
    int len = strlen(s);
    char* ret = malloc(sizeof(char) * len + 1);
    int index = 0;
    for (int i = 0; i < numRows; i++) {
        int t = 0;
        int p = 0;

        if (i == 0) {
            while ((p = 2 * t * (numRows - 1)) < len) {
                ret[index++] = s[p];
                t++;
            }
        }
        else if (i == numRows - 1) {
            while ((p = (2 * t + 1) * (numRows - 1)) < len) {
                ret[index++] = s[p];
                t++;
            }
        }
        else {
            while ((2 * t * (numRows - 1) + i) < len || (2 * (t + 1) * (numRows - 1) - i) < len) {
                if ((2 * t * (numRows - 1) + i) < len && p >= 0) {
                    ret[index++] = s[2 * t * (numRows - 1) + i];
                }
                if ((2 * (t + 1) * (numRows - 1) - i) < len && p >= 0) {
                    ret[index++] = s[2 * (t + 1) * (numRows - 1) - i];
                }
                t++;
            }
        }
    }
    ret[index] = '\0';
    return ret;
}
