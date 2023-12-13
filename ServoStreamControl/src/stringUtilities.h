#pragma once

#include <Arduino.h>
#include <StringSplitter.h>

inline bool isThisStringAValidCommandString(const String commandString)
{
    if (commandString.charAt(0) != '$' || commandString.charAt(1) == ':' ||
        commandString.indexOf(' ') != -1 || commandString.length() <= 1)
        return false;

    return true;
}

inline void splitCommandtStringIntoTwoArguments(const String commandString, String& ptrCommandPrefix, String& ptrCommandArguments)
{
    StringSplitter* splitter = new StringSplitter(commandString, ':', 2);

    ptrCommandPrefix = splitter->getItemAtIndex(0);
    ptrCommandArguments = splitter->getItemAtIndex(1);
}
