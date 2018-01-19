int lengthOfLongestSubstring(char* s) {
    if (!s)
        return 0;
    else if (strlen(s) == 1)
        return 1;

    int ret = 0;
    int i, j;
    int dict[256];
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int inner = 1;
        memset(dict, 0x0, sizeof(int) * 256);
        dict[s[i]] = 1;
        for (int j = i + 1; j < len; j++) {
            if (dict[s[j]])
                break;
            dict[s[j]] = 1;
            inner++;
        }

        ret = ret < inner ? inner : ret;
    }

    return ret;
}
