/* gask's Parameters Library --
 * For making handling command line parameters a cinch. */
#include <string>
#include <unordered_map>

/* All exceptions are of type std::runtime_error. */
class Params {
    public:
        Params();                                         /* Default constructor. If you use this, 
                                                             you need to call parse_params() before
                                                             you can do anything with the class. */

        Params(int argc, char **argv);                    /* Constructor that calls parse_params() 
                                                             for you. */

        void parse(int argc, char **argv);                /* Initializes param_map. Throws an 
                                                             exception if param_map isn't empty, if 
                                                             a duplicate flag is found, or if a 
                                                             value with no flag is given. */

        std::string get(const std::string &key) const;    /* Fetches a param from the map. Returns 
                                                             an empty string if the key has no 
                                                             value, throws an exception if the key 
                                                             isn't present. */
        
        bool exists(const std::string &key) const;        /* Returns true if the key is present in 
                                                             the map. */
        
        void clear();                                     /* Clears the internal map. */
        
        unsigned long size() const;                       /* Returns the number of parameters 
                                                             stored -- ie param_map.size() */
        
        void print_map() const;                           /* Debug: prints the contents of the 
                                                             map */

    protected:
        void add_flag(std::string flag, std::string value);     /* Helper method: adds key / val 
                                                                   pairs to the map and handles 
                                                                   error checking. */

        std::unordered_map<std::string, std::string> param_map; /* The internal storage for 
                                                                   parameters. */
};
