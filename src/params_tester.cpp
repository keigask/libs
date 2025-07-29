#include "params.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    string full_cmd;
    vector<string> cmd_args;
    istringstream sin;

    while (1) {
        printf("[PT] ");
        getline(cin, full_cmd);
        printf("%s\n", full_cmd.c_str());
    }
}
