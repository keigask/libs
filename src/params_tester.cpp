#include "params.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

enum Command {
    cmd_parse,
    cmd_get,
    cmd_exists,
    cmd_clear,
    cmd_size,
    cmd_print,
    cmd_help,
    cmd_quit,
    cmd_unrecognized
};

string to_upper(const string &s) {
    unsigned long i, len;
    string upper;

    upper = s;
    len = upper.size();

    for (i = 0; i < len; i++) {
        if (!(upper[i] >= 'a' && upper[i] <= 'z')) continue;

        upper[i] -= 'a' - 'A';
    } 

    return upper;
}

Command which_command(const string &s) {
    string upper;

    upper = to_upper(s);
    if (upper == "PARSE") return cmd_parse;
    if (upper == "GET") return cmd_get;
    if (upper == "EXISTS") return cmd_exists;
    if (upper == "CLEAR") return cmd_clear;
    if (upper == "SIZE") return cmd_size;
    if (upper == "PRINT") return cmd_print;
    if (upper == "?") return cmd_help;
    if (upper == "Q") return cmd_quit;

    return cmd_unrecognized;
}

void print_commands() {
    printf("Params class testing program.\n");
    printf("All commands are case insensitive\n");
    printf("\n");

    printf("PARSE        -- Parses command line arguments (ie calls parse_params())\n");
    printf("GET <key>    -- Prints the key's value if it's present.\n");
    printf("EXISTS <key> -- Prints if a key exists.\n");
    printf("CLEAR        -- Clears the parameters.\n");
    printf("SIZE         -- Prints the number of parameters recorded.\n");
    printf("PRINT        -- Prints the state of the internal map.\n");
    printf("?            -- Prints this message.\n");
    printf("Q            -- Quits.\n");
}

int main(int argc, char **argv) {
    string full_cmd, arg, got;
    vector<string> cmd_args;
    istringstream sin;
    Params params;
    bool found_it;
    int i;

    /* Print command line arguments. */
    printf("argv: ");
    for (i = 0; i < argc; i++) {
        if (i != 0) printf(" ");
        printf("%s", argv[i]);
    }
    printf("\n");

    while (1) {
        printf("[PT] ");
        getline(cin, full_cmd);
        
        cmd_args.clear();
        sin.clear();

        sin.str(full_cmd);
        while (sin >> arg) cmd_args.push_back(arg);

        if (cmd_args.size() == 0) {
            printf("\n");
            return 0;
        }

        switch (which_command(cmd_args[0])) {
            case cmd_parse:
                if (cmd_args.size() != 1) {
                    fprintf(stderr, "usage: PARSE\n");
                    continue;
                }

                try {
                    params.parse(argc, argv);
                }
                catch (runtime_error &e) {
                    fprintf(stderr, "An exception occured: %s\n", e.what());
                }

                break;

            case cmd_get:
                if (cmd_args.size() != 2) {
                    fprintf(stderr, "usage: GET <key>\n");
                    continue;
                }

                try {
                    got = params.get(cmd_args[1]);
                }
                catch (runtime_error &e) {
                    fprintf(stderr, "An exception occured: %s\n", e.what());
                }

                break;

            case cmd_exists:
                if (cmd_args.size() != 2) {
                    fprintf(stderr, "usage: EXISTS <key>\n");
                    continue;
                }

                found_it = params.exists(cmd_args[1]);
                printf("%s\n", (found_it) ? "true" : "false");

                break;

            case cmd_clear:
                if (cmd_args.size() != 1) {
                    fprintf(stderr, "usage: CLEAR\n");
                    continue;
                }

                params.clear();
                break;

            case cmd_size:
                if (cmd_args.size() != 1) {
                    fprintf(stderr, "usage: SIZE\n");
                    continue;
                }

                printf("%lu\n", params.size());
                break;

            case cmd_print:
                if (cmd_args.size() != 1) {
                    fprintf(stderr, "usage: PRINT\n");
                    continue;
                }

                params.print_map();
                break;

            case cmd_help:
                print_commands();
                break;

            case cmd_quit:
                exit(1);
                break;

            default:
                fprintf(stderr, "Unknown command: %s\n", cmd_args[0].c_str());
        }
    }
}
