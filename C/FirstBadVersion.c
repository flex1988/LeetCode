// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n)
{
    long int low = 1;
    long int high = n;
    long int idx = (low + high) / 2;
    while (low < high) {
        if (isBadVersion(idx)) {
            if (!isBadVersion(idx - 1))
                return idx;
            high = idx;
            idx = (low + high) / 2;
        }
        else {
            if (isBadVersion(idx + 1))
                return ++idx;
            low = idx;
            idx = (low + high) / 2;
        }
    }
}
