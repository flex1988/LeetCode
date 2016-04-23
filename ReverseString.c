void swap(char* a, char* b);
char* reverseString(char* s)
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        swap(s + i, s + len - 1 - i);
    }
    return s;
}

void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
