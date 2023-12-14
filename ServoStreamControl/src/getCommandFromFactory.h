#pragma once

#include <Arduino.h>
#include "./shell/BaseCommand.h"
#include "./commands/PingCommand.h"

inline BaseCommand* getCommandFromFactory(const String& commandPrefix, const String& commandArguments)
{
    if (commandPrefix.equals("ping"))
        return new PingCommand(commandArguments);
    
    else
        return new BaseCommand();
}
