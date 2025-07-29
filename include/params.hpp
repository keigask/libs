/* gask's Parameters Library --
 * For making handling command line parameters a cinch. */
#include <string>
#include <unordered_map>

const std::string PARAM_SENTINEL_VALUE = "*SENTINEL*";    /* Used as the value when parameters have 
                                                             no value. */

class Params {
    public:
        Params();                                         /* Default constructor. If you use this, 
                                                             you need to call parse_params() before you can do anything with the class. */
        Params(int argc, char **argv);                    /* Constructor that calls parse_params() 
                                                             for you. */

        void parse_params(int argc, char **argv);         /* Initializes param_map. Throws an 
                                                             exception if param_map isn't empty. */
        std::string get_param(const std::string &key) const;    /* Fetches a param from the map. 
                                                                   Returns NULL if the key doesn't 
                                                                   exist, or PARAM_SENTINEL_VALUE 
                                                                   if the key has no value. */
        bool param_exists(const std::string &key) const;  /* Returns true if the key is present in 
                                                             the map. */
        void clear();                                     /* Clears the internal map. */
        unsigned long size() const;                       /* Returns the number of parameters 
                                                             stored -- ie param_map.size() */

    protected:
        std::unordered_map<std::string, std::string> param_map; /* The internal storage for 
                                                                   parameters. */
};
