int numDecodings(char* s)
{
    int len = strlen(s);
    if (len == 0)
        return 0;
    int result[len];
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            char t[2];
            t[0] = s[0];
            t[1] = '\0';
            int val = atoi(&t);
            if (val > 0 && val < 10)
                result[0] = 1;
            else
                result[0] = 0;
        }
        else {
            result[i] = 0;
            char t[2];
            t[0] = s[i];
            t[1] = '\0';
            int val = atoi(&t);

            if (val > 0 && val < 10)
                result[i] += result[i - 1];
            char t1[3];
            t1[0] = s[i - 1];
            t1[1] = s[i];
            t1[2] = '\0';
            int val1 = atoi(&t1);
            if (val1 > 9 && val1 < 27) {
                if (i >= 2)
                    result[i] += result[i - 2];
                else
                    result[i] += 1;
            }
        }
    }
    return result[len - 1];
}
