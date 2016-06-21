char* addBinary(char* a, char* b)
{
    int a_len = strlen(a);
    int b_len = strlen(b);
    int ret_len = a_len > b_len ? a_len + 1 : b_len + 1;
    char* ret = (char*)malloc(sizeof(char) * (ret_len + 1));
    ret[ret_len] = '\0';
    int index = ret_len - 1;
    bool isCarry = false;
    while (a_len && b_len) {
        int t = a[--a_len] - '0' + b[--b_len] - '0' + (isCarry ? 1 : 0);
        if (t > 1) {
            isCarry = true;
            ret[index--] = t - 2 + '0';
        }
        else {
            isCarry = false;
            ret[index--] = t + '0';
        }
    }

    while (a_len) {
        int t = a[--a_len] - '0' + (isCarry ? 1 : 0);
        if (t > 1) {
            isCarry = true;
            ret[index--] = t - 2 + '0';
        }
        else {
            isCarry = false;
            ret[index--] = t + '0';
        }
    }
    while (b_len) {
        int t = b[--b_len] - '0' + (isCarry ? 1 : 0);
        if (t > 1) {
            isCarry = true;
            ret[index--] = t - 2 + '0';
        }
        else {
            isCarry = false;
            ret[index--] = t + '0';
        }
    }
    if (isCarry) {
        ret[index--] = '1';
    }

    return ret + index + 1;
}
