bool isPalindrome(char* s)
{
    int len = strlen(s);
    char str[len];
    int idx = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(s[i]))
            str[idx++] = s[i];
    }

    int slen = idx;
    for (int i = 0; i < slen / 2; i++) {
        if ((str[i] == str[slen - i - 1]) || (str[i] != str[slen - i - 1] && (str[i] - str[slen - i - 1] == 32 || str[i] - str[slen - i - 1] == -32)))
            ;
        else
            return false;
    }
    return true;
}
