#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatenate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    char *result = malloc(len1 + len2 + 1);
    if (result == NULL) {
        my_error("malloc failed");
    }

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

int main(int argc, char *argv[])
{
    char *s;
    char *tmp;


    s = my_strcat("", argv[0]);

    for (int i = 1; i < argc; i++) {
        tmp = my_strcat(s, argv[i]);
        free(s);      // free old string
        s = tmp;      // update to new string
    }

    printf("%s\n", s);

    free(s); // free final string
    return 0;
}
