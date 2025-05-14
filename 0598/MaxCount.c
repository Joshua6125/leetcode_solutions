
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize)
{
    if (!ops) return m*n;

    int min_m = m;
    int min_n = n;
    for (int i = 0; i < opsSize; i++) {
        if (min_m > ops[i][0]) min_m = ops[i][0];
        if (min_n > ops[i][1]) min_n = ops[i][1];
    }

    return min_m * min_n;
}
