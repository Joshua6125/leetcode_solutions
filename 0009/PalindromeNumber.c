#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    int numblen = snprintf(NULL, 0, "%d", x) + 1;
    char numb[numblen];

    sprintf(numb, "%d", x);
    char reverse[numblen];

    for (int i = 0; i < numblen - 1; i++) {
        reverse[numblen - i - 2] = numb[i];
    }
    reverse[numblen -1] = '\0';

    if (strcmp(reverse, numb) == 0) {
        return true;
    }
    else {
        return false;
    }
    return 0;
}