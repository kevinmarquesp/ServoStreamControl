#pragma once

#include <Arduino.h>
#include "./shell/BaseCommand.h"
#include "../commands/PingCommand.h"
#include "../servos/ServosInfo.h"

inline BaseCommand* commandFactory(const String cmd, const String arg, const ServosInfo& currServosInfo)
{
    if (cmd.equals("ping"))
        return new PingCommand(arg);
    
    else
        return new BaseCommand();
}