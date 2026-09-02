#include <stdio.h>
#include <stdlib.h>

int len(char s[]);
char* concat(char s1[], char s2[]);
int stringCompare(char s1[], char s2[]);
char* insertSubstring(char s1[], char s2[], int pos);
char* deleteSubstring(char s1[], int begin, int end);

int main() {
    char str1[] = "Hello";
    char str2[] = "World";

    printf("Length of %s: %d\n", str1, len(str1));
    printf("Concatenated String: %s\n", concat(str1, str2));
    printf("are the strings same?: %d\n", stringCompare(str1, "Hello"));
    printf("Added Substring: %s\n", insertSubstring(str1, " Zahil Mota", 5));
    printf("Deleted Substring: %s\n", deleteSubstring(str1, 0, 2));

    return 0;
}

int len(char s[]) {
    int l = 0;

    while (s[l] != '\0') {
        l++;
    }

    return l;
}

char* concat(char s1[], char s2[]) {
    static char cs[256] = "";
    int i = 0, j = 0;

    while (s1[i] != '\0') {
        cs[i] = s1[i];
        i++;
    }

    while (s2[j] != '\0') {
        cs[i] = s2[j];
        i++;
        j++;
    }

    cs[i] = '\0';

    return cs;
}

int stringCompare(char s1[], char s2[]) {
    static int eq = 1;
    if (len(s1) == len(s2)) {
        for (int i = 0; i < len(s1); i++) {
            if (s1[i] != s2[i]) {
                eq = 0;
                break;
            }
        }
    }
    return eq;
}

char* insertSubstring(char s1[], char s2[], int pos) {
    static char coms[256];
    int i = 0, j = 0, k = 0;

    for (i = 0; i < pos && s1[i] != '\0'; i++) {
        coms[i] = s1[i];
    }

    j = i;
    for (int x = 0; s2[x] != '\0'; x++) {
        coms[j] = s2[x];
        j++;
    }

    for (int x = i; s1[x] != '\0'; x++) {
        coms[j] = s1[x];
        j++;
    }

    coms[j] = '\0';
    return coms;
}

char* deleteSubstring(char s1[], int begin, int end) {
    static char dels[256];

    int i = 0;

    for (; i < begin && s1[i] != '\0'; i++) {
        dels[i] = s1[i];
    }

    for (int j = end; s1[j] != '\0'; j++) {
        dels[i++] = s1[j];
    }

    dels[i] = '\0';

    return dels;
}



/*
Write a program to perform following string operations without using string
handling functions:
a.) length of the string
b.) string concatenation
c.) string comparison
d.) to insert a sub string
e.) to delete a substring
*/
