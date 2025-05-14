#include <stdio.h>

int minimumOneBitOperationsRec(int n, int par)
{
    if (!n) return 0;

    int msbp = 31 - __builtin_clz(n);

    return minimumOneBitOperationsRec(n ^= (1 << msbp), -par) + par * (1 << (msbp + 1));
}

int minimumOneBitOperations(int n)
{
    if (!n) return 0;

    return __builtin_popcount(n) % 2 ? minimumOneBitOperationsRec(n, 1) - 1 :
                                       minimumOneBitOperationsRec(n, 1);
}

int main()
{
    printf("test 0: %d must be 0\n", minimumOneBitOperations(0));
    printf("test 1: %d must be 1\n", minimumOneBitOperations(1));
    printf("test 2: %d must be 3\n", minimumOneBitOperations(2));
    printf("test 3: %d must be 2\n", minimumOneBitOperations(3));
    printf("test 4: %d must be 7\n", minimumOneBitOperations(4));
    printf("test 5: %d must be 6\n", minimumOneBitOperations(5));
    printf("test 6: %d must be 4\n", minimumOneBitOperations(6));
    printf("test 7: %d must be 5\n", minimumOneBitOperations(7));

    return 0;
}