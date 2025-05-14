int removeDuplicates(int* nums, int numsSize)
{
    int found_nums = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[found_nums] = nums[i];
            found_nums++;
        }
    }
    return found_nums;
}
