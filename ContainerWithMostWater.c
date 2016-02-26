int maxArea(int* height, int heightSize)
{
    if (heightSize == 0)
        return 0;
    int water = (heightSize - 1) * (height[heightSize - 1] > height[0] ? height[0] : height[heightSize - 1]);
    int i = 0, j = heightSize - 1;

    while (i < j) {
        if (height[i] < height[j]) {
            i++;
            int t = (j - i) * (height[j] > height[i] ? height[i] : height[j]);
            water = water > t ? water : t;
        }
        else {
            j--;
            int t = (j - i) * (height[j] > height[i] ? height[i] : height[j]);
            water = water > t ? water : t;
        }
    }
    return water;
}
