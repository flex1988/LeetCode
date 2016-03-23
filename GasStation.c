int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    for (int i = 0; i < gasSize;) {
        int left = gas[i];
        int t = i;
        while (left >= cost[t]) {
            left -= cost[t];
            if (t == gasSize - 1) {
                t = 0;
                left += gas[t];
            }
            else
                left += gas[++t];

            if (t == i)
                return i;
        }
        i = t > i ? t : i + 1;
    }
    return -1;
}
