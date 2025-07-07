#include <stdio.h>
#include <string.h>

#define DICTIONARY_SIZE 34000000
#define TRUE 1

static char dictionary[DICTIONARY_SIZE] = {0};

int main() {
    int n;
    scanf("%d", &n);

    char command[8];
    char str[13];
    long long key;
    int j;

    for (int i = 0; i < n; i++) {
        scanf("%s %s", command, str);

        key = 1;

        for (j = 0; str[j] != '\0'; j++) {
            key = key * 5 + (str[j] == 'A' ? 1 : str[j] == 'C' ? 2 : str[j] == 'G' ? 3 : 4);
        }

        if (strcmp(command, "insert") == 0) {
            dictionary[key] = TRUE;
        } else {
            if (dictionary[key] == TRUE) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }

    return 0;
}