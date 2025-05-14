int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *arr = malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        for (int k = i + 1; k < numsSize; k++) {
            if (nums[i] + nums[k] == target) {
                arr[0] = i;
                arr[1] = k;
                return arr;
            }
        }
    }
    return 0;
}