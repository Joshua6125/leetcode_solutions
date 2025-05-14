#include <string.h>

int romanToInt(char* s)
{
    int num = 0;
    for (int i = strlen(s) - 1; i > 0; i--) {
        char letter = s[i];
        switch (letter) {
            case 'I':
                num += 1;
                break;
            case 'V':
                if (s[i - 1] == 'I') {
                    num += 3;
                } else {
                    num += 5;
                }
                break;
            case 'X':
                if (s[i - 1] == 'I') {
                    num += 8;
                } else {
                    num += 10;
                }
                break;
            case 'L':
                if (s[i - 1] == 'X') {
                    num += 30;
                } else {
                    num += 50;
                }
                break;
            case 'C':
                if (s[i - 1] == 'X') {
                    num += 80;
                } else {
                    num += 100;
                }
                break;
            case 'D':
                if (s[i - 1] == 'C') {
                    num += 300;
                } else {
                    num += 500;
                }
                break;
            case 'M':
                if (s[i - 1] == 'C') {
                    num += 800;
                } else {
                    num += 1000;
                }
                break;
            default:
                break;
        }
    }
    if (s[0] == 'I') {
        num += 1;
    } else if (s[0] == 'V') {
        num += 5;
    } else if (s[0] == 'X') {
        num += 10;
    } else if (s[0] == 'L') {
        num += 50;
    } else if (s[0] == 'C') {
        num += 100;
    } else if (s[0] == 'D') {
        num += 500;
    } else {
        num += 1000;
    }
    return num;
}