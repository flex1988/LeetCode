bool isVowels(char* c);
void swap(char* a, char* b);

char* reverseVowels(char* s)
{
    int len = strlen(s);
    int l = 0;
    int h = len - 1;
    while (l < h) {
        if (!isVowels(s + l)) {
            l++;
            continue;
        }
        if (!isVowels(s + h)) {
            h--;
            continue;
        }
        swap(s + l, s + h);
        l++;
        h--;
    }
    return s;
}

bool isVowels(char* c) { return *c == 'a' || *c == 'e' || *c == 'i' || *c == 'o' || *c == 'u' || *c == 'A' || *c == 'E' || *c == 'I' || *c == 'O' || *c == 'U'; }

void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
