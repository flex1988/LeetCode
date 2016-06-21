char* longestCommonPrefix(char** strs, int strsSize)
{
    char* ret = calloc(100, sizeof(char));
    int flag = 1;
    int index = 0;
    if (strsSize == 0)
        return "";
    while (flag && strs[0][index]) {
        char t = strs[0][index];
        for (int i = 0; i < strsSize; i++) {
            if (strs[i][index] != t) {
                flag = 0;
                break;
            }
        }
        if (flag)
            ret[index++] = t;
    }
    ret[index++] = '\0';
    return ret;
}
