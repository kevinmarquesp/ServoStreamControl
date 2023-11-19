#pragma once

#include <Arduino.h>
#include <StringSplitter.h>

inline bool isThisStringAValidCommandString(const String cmd)
{
    if (cmd.charAt(0) != '$')
        return false;

    return true;
}

inline void spliCommandtStringIntoTwoArguments(const String commandString, String& cmd, String& arg)
{
    StringSplitter* splitter = new StringSplitter(commandString, ':', 2);

    cmd = splitter->getItemAtIndex(0);
    arg = splitter->getItemAtIndex(1);
}