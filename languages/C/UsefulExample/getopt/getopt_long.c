#include <stdio.h>
#include <getopt.h>

/* Be aware that 'c' and 'd' should also be included here */
char *short_options = "ab:cd:";
struct option long_options[] = {
    /* option=count, no argument, no assign value, return 'c' for getopt_long*/
    {"count",  no_argument,       NULL, 'c'},
    {"delete", required_argument, NULL, 'd'},
    { 0, 0, 0, 0},
};

int main(int argc, char *argv[])
{
    int cmd_opt = 0;
    while ((cmd_opt = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
        switch (cmd_opt) {
            // no arg
            case 'a':
                printf("Read %c and have no arg\n", cmd_opt);
                break;
            // 1 arg
            case 'b':
                printf("Read %c and arg=%s\n", cmd_opt, optarg);
                break;
            case 'c':
                printf("Read %c or count.\n", cmd_opt);
                break;
            case 'd':
                printf("Read %c or delete. ", cmd_opt);
                printf("arg: %s\n", optarg);
                break;
            // missing arg or illegal option
            case '?':
                printf("Illegal option %c usage\n", cmd_opt);
                break;
            default:
                printf("No supported option %c\n", cmd_opt);
                break;
        }
    }

    if (argc > optind) {
        // Extra argument
        printf("Extra argument: \n");
        for (int i = optind; i < argc; i++) {
            printf("* %s\n", argv[i]);
        }
    }

    return 0;
}
