int removeElement(int A[], int n, int elem)
{
    int index = 0;
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == elem) {
            index++;
        }
        else {
            if (index > 0) {
                A[i - index] = A[i];
            }
            len++;
        }
    }
    return len;
}
