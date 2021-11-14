#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args( char * line);

int charcount(char * string, char c) {
    int i = 0;
    int count = 0;
    for (i; i < strlen(string); i++)
        if (string[i] == c)
            count++;
    return count;
}

char ** parse_args( char * line ) {
    int i;
    int num = 2 + charcount(line, ' ');
    char **args = malloc(num * sizeof(char *));
    char *curr = line;
    char * token;

    for (i = 0; i < num; i++) {
        token = strsep(&curr, " ");
        args[i] = token;

    }
    args[num - 1] = 0;
    return args;
}

int main() {
    int i;
    char line[] = "ls -l -a";
    char ** args = parse_args(line);
    execvp(args[0], args);


    return 0;

}
