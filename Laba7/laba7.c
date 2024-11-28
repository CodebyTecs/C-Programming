#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    int len = strlen(str);
    char *words[len]; 
    int s = 0;

    char *word = strtok(str, " ,.-"); 
    while (word != NULL && s < len) {
        words[s] = word;
        word = strtok(NULL, " ,.-");
        s++;
    }

    for (int i = s - 1; i >= 0; i--) { 
        printf("%s", words[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}