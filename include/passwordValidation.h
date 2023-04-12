#include <string>

/**
 * This function checks whether a given password is valid or not. A password
 * is considered valid if it contains at least one uppercase letter, one lowercase
 * letter, one digit, one special character, and one comma. The function returns
 * true if the password is valid, and false otherwise.
 *
 * @param password The password to validate
 * @return True if the password is valid, false otherwise
 */
bool validatePassword(const std::string& password) {
    bool has_special_character = false;
    bool has_upper = false;
    bool has_lower = false;
    bool has_number = false;
    bool has_comma = false;

    for(const auto c : password) {
        has_special_character = has_special_character || (c >= '!' && c <= '/' || c >= ':' && c <= '@' || c >= '[' && c <= '`' || c >= '{' && c <= '~');
        has_upper = has_upper || (c >= 'A' && c <= 'Z');
        has_lower = has_lower || (c >= 'a' && c <= 'z');
        has_number = has_number || (c >= '0' && c <= '9');
        has_comma = has_comma || (c == ',');
    }

    return has_special_character && has_upper && has_lower && has_number && has_comma;
}