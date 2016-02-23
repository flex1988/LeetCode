int lengthOfLongestSubstring(char* s)
{
    int ret = 0;
    int length = 0;
    int* array = calloc(256, sizeof(int));
    int slen = strlen(s);
    int last = 0;
    int i = 0;
    for (; last < slen, i < slen;) {

        if (array[s[i] - '\0'] == 0) {
            length++;
            array[s[i] - '\0'] = i + 1;
            i++;
        }
        else {

            ret = ret > length ? ret : length;
            last = array[s[i] - '\0'];
            i = last;
            length = 0;
            free(array);
            array = calloc(256, sizeof(int));
        }
    }
    ret = ret > length ? ret : length;
    return ret;
}
