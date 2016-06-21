bool isAnagram(char* s, char* t)
{
    int a[26] = { 0 };
    int idx = 0;
    while (s[idx] != '\0') {
        a[s[idx++] - 'a']++;
    }
    idx = 0;
    while (t[idx] != '\0') {
        a[t[idx++] - 'a']--;
    }
    for (int j = 0; j < 26; j++) {
        if (a[j] != 0)
            return false;
    }
    return true;
}
