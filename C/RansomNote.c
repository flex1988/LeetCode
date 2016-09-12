bool
canConstruct(char* ransomNote, char* magazine)
{
    int* dict = calloc(26, sizeof(int));
    int len_m = strlen(magazine);
    for (int i = 0; i < len_m; i++) {
        dict[magazine[i] - 'a']++;
    }
    int len_r = strlen(ransomNote);
    for (int i = 0; i < len_r; i++) {
        dict[ransomNote[i] - 'a']--;
        if (dict[ransomNote[i] - 'a'] < 0) return false;
    }
    return true;
}
