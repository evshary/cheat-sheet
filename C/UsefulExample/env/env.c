#include <stdlib.h> // for getenv
#include <stdio.h>

int main()
{
    printf("PATH: %s\n", getenv("PATH"));
    printf("--------------------\n");
    if (getenv("MY_ENV") == NULL) {
        printf("You haven't set environment variables: MY_ENV\n");
        setenv("MY_ENV", "set_by_program", 0);
        // If you want to overwrite, use 1 in the last argument.
        //setenv("MY_ENV", "set_by_program", 1);
        printf("set MY_ENV to %s\n", getenv("MY_ENV"));
        printf("Note that the setenv here won't affect your shell.\n");
    } else {
        printf("MY_ENV: %s\n", getenv("MY_ENV"));
    }
    return 0;
}
