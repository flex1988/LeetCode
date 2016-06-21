int strStr(char* haystack, char* needle)
{
    int index = 0;
    char* p = haystack;
    if (*needle == '\0' && *haystack == '\0')
        return 0;
    else if (*haystack == '\0' && *needle != '\0')
        return -1;
    while (*p != '\0') {
        char* tp = p;
        char* tn = needle;
        while (*tp == *tn && *tp != '\0' && *tn != '\0') {
            tp++;
            tn++;
        }
        if (*tn == '\0')
            return index;
        else if (*tp == *tn && *tp == '\0')
            return index;
        else if (*tp == '\0' && *tn != '\0')
            return -1;
        else {
            p++;
            index++;
        }
    }
    if (*p == *needle && *p == '\0')
        return 0;
    return -1;
}
