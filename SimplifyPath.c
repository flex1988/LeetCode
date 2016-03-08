char* simplifyPath(char* path)
{
    char** ret = malloc(sizeof(char*) * 200);
    int index = 0;
    char* p = strtok(path, "/");

    while (p != NULL) {
        if (strcmp(p, "..") == 0) {
            if (index > 0)
                index--;
        }
        else if (strcmp(p, ".") == 0)
            ;
        else
            ret[index++] = p;
        p = strtok(NULL, "/");
    }

    char* result = malloc(sizeof(char) * 1000);

    int idx = 1;
    result[0] = '/';

    for (int i = 0; i < index; i++) {
        memcpy(result + idx, ret[i], strlen(ret[i]) * sizeof(char));
        idx += strlen(ret[i]);
        if (i != index - 1)
            result[idx++] = '/';
    }
    result[idx++] = '\0';
    return result;
}
