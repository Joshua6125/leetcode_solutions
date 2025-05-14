#include <stdio.h>
#include <string.h>

int minimumLength(char* s)
{
    int n = strlen(s);

    char* p1 = s;
    char* p2 = p1 + n - 1;

    char temp = *p1;

    while (p1 < p2) {
        if (*p1 != *p2) {
            return (int)(p2 - p1) + 1;
        }

        temp = *p1;

        p1++;
        while (p1 <= p2 && *p1 == temp) {
            p1++;
        }

        p2--;
        while (p1 <= p2 && *p2 == temp) {
            p2--;
        }
    }

    return (p1 == p2) ? 1 : 0;
}



int main()
{

    printf("test 1: %d\n", minimumLength("ca"));
    printf("test 2: %d\n", minimumLength("cabaabac"));
    printf("test 3: %d\n", minimumLength("aabccabba"));
    printf("test 4: %d\n", minimumLength("bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb"));

    return 0;
}