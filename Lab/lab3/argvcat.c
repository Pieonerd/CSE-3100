
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2)
{
    // TODO
    char *concatenate = malloc(strlen(s1) + strlen(s2) + 1);
    if(concatenate == NULL)
	{
		my_error("Cannot allocate memory\n");
	}

    strcpy(concatenate, s1);
    strcat(concatenate, s2);
    return concatenate;
}

int main(int argc, char *argv[])
{
    char *s;

    s = my_strcat("", argv[0]);

    for (int i = 1; i < argc; i ++) {
        char *temp = my_strcat(s, argv[i]);
        free(s);
        s = temp;
    }

    printf("%s\n", s);

    free(s);

    return 0;
}