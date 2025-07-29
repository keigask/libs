#include "params.hpp"
#include <string>
using namespace std;

Params::Params() {

}

Params::Params(int argc, char **argv) {
    (void) argc;
    (void) argv;
}
 
void Params::parse(int argc, char **argv) {
    (void) argc;
    (void) argv;
}

string Params::get(const std::string &key) const {
    (void) key;

    return "";
}

bool Params::exists(const std::string &key) const {
    (void) key;

    return false;
}
 
void Params::clear() {

}

unsigned long Params::size() const {
    return 0;
}

 
