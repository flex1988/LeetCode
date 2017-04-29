int r2i(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(char* s) {
    int i;
    int sum = 0;
    int prev, cur;
    for (i = 0; i < strlen(s); i++) {
        if (i == 0) {
            sum += r2i(s[i]);
            continue;
        }
        cur = r2i(s[i]);
        prev = r2i(s[i - 1]);
        if (prev < cur)
            sum += (cur - 2 * prev);
        else
            sum += cur;
    }
    return sum;
}
