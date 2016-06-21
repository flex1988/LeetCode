bool isValid(char* s)
{
    int len = strlen(s);
    char stack[len];
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[index++] = s[i];
        }
        else {
            if (s[i] == ')') {
                if (stack[index - 1] == '(')
                    index--;
                else
                    return false;
            }
            else if (s[i] == '}') {
                if (stack[index - 1] == '{')
                    index--;
                else
                    return false;
            }
            else if (s[i] == ']') {
                if (stack[index - 1] == '[')
                    index--;
                else
                    return false;
            }
        }
    }
    return index == 0;
}
