#include <string.h>

int strStr(char* haystack, char* needle)
{
    if (strlen(haystack) < strlen(needle)) {
        return -1;
    }

    int counter = 0;
    for (int i = 0; i < strlen(haystack) - strlen(needle) + 1; i++) {
        for (int j = 0; j < strlen(needle); j++) {
            if (haystack[i + j] == needle[j]) {
                counter++;
            }
        }

        if (counter == strlen(needle)) {
            return i;
        }
        counter = 0;
    }

    return -1;
}
