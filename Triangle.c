int minimumTotal(int** triangle, int numRows)
{
    int arr[numRows][numRows];

    for (int i = 0; i < numRows; i++) {
        if (i == 0)
            arr[0][0] = triangle[0][0];
        else {
            for (int j = 0; j <= i; j++) {
                if (j == 0)
                    arr[i][j] = arr[i - 1][j] + triangle[i][j];
                else if (j == i)
                    arr[i][j] = arr[i - 1][j - 1] + triangle[i][j];
                else
                    arr[i][j] = arr[i - 1][j - 1] + triangle[i][j] < arr[i - 1][j] + triangle[i][j] ? arr[i - 1][j - 1] + triangle[i][j] : arr[i - 1][j] + triangle[i][j];
            }
        }
    }
    int sum = arr[numRows - 1][0];
    for (int j = 1; j < numRows; j++) {
        sum = arr[numRows - 1][j] > sum ? sum : arr[numRows - 1][j];
    }
    return sum;
}
