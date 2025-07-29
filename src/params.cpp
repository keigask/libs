#include "params.hpp"
#include <string>
using namespace std;

Params::Params() {

}

Params::Params(int argc, char **argv) {
    (void) argc;
    (void) argv;
}
 
void Params::parse_params(int argc, char **argv) {
    (void) argc;
    (void) argv;
}

string Params::get_param(const std::string &key) const {
    (void) key;

    return "";
}

bool Params::param_exists(const std::string &key) const {
    (void) key;

    return false;
}
 
void Params::clear() {

}

unsigned long Params::size() const {
    return -1;
}

 
