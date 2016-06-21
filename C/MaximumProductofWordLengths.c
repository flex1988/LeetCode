int maxProduct(char** words, int wordsSize)
{
    int ret = 0;
    int* mask = malloc(sizeof(int) * wordsSize);
    memset(mask, 0, sizeof(int) * wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        int wlen = strlen(words[i]);

        for (int j = 0; j < wlen; j++)
            mask[i] |= 1 << (words[i][j] - 'a');
        for (int k = 0; k < i; k++) {
            if (!(mask[k] & mask[i])) {
                int t = strlen(words[k]) * strlen(words[i]);
                ret = ret > t ? ret : t;
            }
        }
    }
    return ret;
}
