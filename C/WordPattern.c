bool wordPattern(char* pattern, char* str)
{
    char** htable = calloc(26, sizeof(char*));
    char* o_str = strdup(str);
    int len = strlen(pattern);
    char* t;

    for (int i = 0; i < len; i++) {

        if (i == 0) {
            t = strtok(o_str, " ");
        }
        else {
            t = strtok(NULL, " ");
        }
        if (t == NULL)
            return false;

        if (htable[pattern[i] - 'a'] == NULL) {
            for (int i = 0; i < 26; i++) {
                if (htable[i] != NULL && strcmp(htable[i], t) == 0) {
                    return false;
                }
            }
            htable[pattern[i] - 'a'] = t;
        }
        else if (strcmp(htable[pattern[i] - 'a'], t) != 0) {
            return false;
        }
    }
    if (strtok(NULL, " ") != NULL)
        return false;
    return true;
}
