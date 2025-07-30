#include "params.hpp"
#include <string>
#include <stdexcept>
using namespace std;

/* Checks if a string starts with '-'. */
bool starts_with_dash(const string &s) {
    if (s.size() == 0) return false;
    return (s[0] == '-');
}

/* Default constructor. No initialization is performed here. */
Params::Params() {
    initialized = false;
}

/* Constructor that calls parse() for you. */
Params::Params(int argc, char **argv) {
    parse(argc, argv);
}

/* Parses argv and populates param_map -- initializes the class. */
void Params::parse(int argc, char **argv) {
    int i;
    string cur_key, working_val;

    if (initialized) {
        throw runtime_error("Attempted to parse parameters with parameters already stored.");
    }

    cur_key = "";
    working_val = "";
    for (i = 1; i < argc; i++) {
        /* Collect our value for the current flag. */
        
        if (!starts_with_dash(argv[i])){
            if (working_val != "") working_val += ' ';
            working_val += argv[i];
            continue;
        }

        /* Otherwise, add what we've got to the list and reset. */
        
        if (cur_key != "") add_flag(cur_key, working_val);

        cur_key = argv[i];
        working_val = "";
    }

    /* Once more so we don't miss the last flag. */
    if (cur_key != "") add_flag(cur_key, working_val);

    initialized = true;
}

string Params::get(const std::string &key) const {
    unordered_map<string, string>::const_iterator pit;
    string err;

    if (!initialized) throw runtime_error("Attempt to get value while uninitialized.");

    pit = param_map.find(key);
    if (pit == param_map.end()) {
        err = "Attempted to get value for non-existant key \'" + key + "\'."; 
        throw runtime_error(err);
    }

    return pit->second;
}

bool Params::exists(const std::string &key) const {
    return (param_map.find(key) != param_map.end());
}
 
/* Reset the class to an uninitialized state. */
void Params::clear() {
    param_map.clear();
    initialized = false;
}

/* Fetch the map's size. */
unsigned long Params::size() const {
    return param_map.size();
}

/* Prints the current state of the map. */
void Params::print_map() const {
    unordered_map<string, string>::const_iterator pit;

    for (pit = param_map.begin(); pit != param_map.end(); pit++) {
        printf("KEY: %-15s VAL: %-20s\n", pit->first.c_str(), pit->second.c_str());
    }
}

/* Adds a flag to the internal map. */
void Params::add_flag(std::string flag, std::string value) {
    if (flag == "" && value != "") {
        throw runtime_error("Found a value with no associated flag.");
    }
    else if (param_map.find(flag) != param_map.end()) {
        throw runtime_error("Found a duplicate flag.");
    }
        
    param_map[flag] = value;
}
