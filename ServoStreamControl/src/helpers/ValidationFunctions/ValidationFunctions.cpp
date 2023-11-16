#include <StringSplitter.h>
#include "./ValidationFunctions.h"

const u8 COMMANDS_AMMOUNT = 1;

String validCommandsArray[COMMANDS_AMMOUNT] = {
    "$set",  // command to tell the app how much servos it has to deal with
};

uint8_t validateCommandString(String commandString)
{
    if (commandString.charAt(0) != '$')
        return 1;

    StringSplitter* commandStringSplited = new StringSplitter(commandString, ':', 2);
    String commandName = commandStringSplited->getItemAtIndex(0);
    u8 validCommandsCounter = 0;

    for (u8 i = 0; i < COMMANDS_AMMOUNT; ++i)
        if (commandName == validCommandsArray[i])
            ++validCommandsCounter;

    if (validCommandsCounter != COMMANDS_AMMOUNT)
        return 2;

    return 0;
}