#pragma once

#include <Arduino.h>
#include "status_t.h"

inline void cleanUpUserInputString_l(const String* userString) {
    userString->replace(" ", "");
}

inline status_t validateCommandString(const String userCommandString) {
    cleanUpUserInputString_l(&userCommandString);

    if (userCommandString.charAt(0) != '$')
        return {false, "string specified is not a valid command string"};

    else if (userCommandString.charAt(userCommandString.length()) == ':')
        return {false, "command prefix (arguments) not specified"};

    return {true, ""};
}
