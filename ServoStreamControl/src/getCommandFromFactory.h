#pragma once

#include <Arduino.h>
#include "./shell/BaseCommand.h"
#include "./commands/PingCommand.h"
#include "./commands/AttachCommand.h"

inline BaseCommand* getCommandFromFactory(const String& commandPrefix, const String& commandArguments)
{
    if (commandPrefix.equals("ping"))
        return new PingCommand(commandArguments);

    else if (commandPrefix.equals("att"))
        return new AttachCommand(commandArguments);
    
    else
        return new BaseCommand();
}
