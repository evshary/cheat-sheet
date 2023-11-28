#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int cmd_opt = 0;
    while (1) {
        cmd_opt = getopt(argc, argv, "ab:"); 

        // end condition
        if (cmd_opt == -1) {
            break;
        }

        switch (cmd_opt) {
            // no arg
            case 'a':
                printf("Read %c and have no arg\n", cmd_opt);
                break;
            // 1 arg
            case 'b':
                printf("Read %c and arg=%s\n", cmd_opt, optarg);
                break;
            // missing arg or illegal option
            case '?':
                printf("Illegal option %c usage\n", cmd_opt);
                break;
            default:
                printf("No supported option\n");
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
