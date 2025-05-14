#include <stdio.h>
#include <stdbool.h>

bool canPartition(int* nums, int numsSize)
{
    int sum = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    if (sum % 2 != 0) return false;

    int target = sum >> 1;
    bool* dp = calloc(target + 1, sizeof(bool));
    dp[0] = true;

    for (int i = 0; i < numsSize; i++) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    bool result = dp[target];
    free(dp);
    return result;
}

int main()
{
    int numsarr1[4] = {1,5,11,5};
    int* nums1 = &numsarr1[0];
    printf("Partionable: %s\n", canPartition(nums1, 4) ? "true" : "false");

    int numsarr2[4] = {1,2,3,5};
    int* nums2 = &numsarr2[0];
    printf("Partionable: %s\n", canPartition(nums2, 4) ? "true" : "false");

    int numsarr3[3] = {1,2,5};
    int* nums3 = &numsarr3[0];
    printf("Partionable: %s\n", canPartition(nums3, 3) ? "true" : "false");
}