int removeElement(int* nums, int numsSize, int val)
{
    int counter = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[counter] = nums[i];
            counter++;
        }
    }
    return counter;
}