
char** getLongestSubsequence(char** words, int wordsSize, int* groups,
                             int groupsSize, int* returnSize)
{
    char** arr = malloc(wordsSize*sizeof(char*));

    int type = -1;
    groupsSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (groups[i] != type) {
            arr[groupsSize] = words[i];
            groupsSize++;
            type = groups[i];
        }
    }

    *returnSize = groupsSize;

    return arr;
}
