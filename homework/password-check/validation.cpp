#include "validation.hpp"
#include <algorithm>
#include <iostream>

bool isspecial(char c)
{
    bool special = true;

    if (std::isdigit(c) || std::isalpha(c)) {
        special = false;
    }
    return special;
}

std::string getErrorMessage(ErrorCode code) {
    std::string msg = "Unknown";

    switch (code) {
    case ErrorCode::Ok: {
        msg = "Ok";
        break;
    }
    case ErrorCode::PasswordNeedsAtLeastNineCharacters: {
        msg = "Password needs to have at least nine characters";
        break;
    }
    case ErrorCode::PasswordNeedsAtLeastOneNumber: {
        msg = "Password needs to have at least one number";
        break;
    }
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter: {
        msg = "Password needs to have at least one special character";
        break;
    }
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter: {
        msg = "Password needs to have at least one uppercase letter";
        break;
    }
    case ErrorCode::PasswordsDoNotMatch: {
        msg = "Passwords do not match";
        break;
    }
    default: {
        break;
    }
    }
    return msg;
}

bool doPasswordsMatch(std::string str1, std::string str2) {
    bool the_same = true;

    if (str1.length() == str2.length()) {
        for (size_t i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                the_same = false;
                break;
            }
        }
    } else {
        the_same = false;
    }
    return the_same;
}

ErrorCode checkPasswordRules(std::string str) {
    ErrorCode result = ErrorCode::Ok;

    if (str.length() < 9) {
        result = ErrorCode::PasswordNeedsAtLeastNineCharacters;
    } else if (std::none_of(str.begin(), str.end(), ::isdigit)) {
        result = ErrorCode::PasswordNeedsAtLeastOneNumber;
    } else if (std::none_of(str.begin(), str.end(), isspecial)) {
        result = ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    } else if (std::none_of(str.begin(), str.end(), ::isupper)) {
        result = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return result;
}

ErrorCode checkPassword(std::string str1, std::string str2) {
    ErrorCode result = ErrorCode::PasswordsDoNotMatch;

    if (doPasswordsMatch(str1, str2)) {
        result = checkPasswordRules(str1);
    }
    return result;
}