#pragma once

#include <Arduino.h>
#include "../shell/BaseCommand.h"
#include "../shell/CmdOutput_t.h"
#include "../shell/CommandsIDs.h"

class PingCommand : public BaseCommand
{
private:
    String _argument;

public:
    PingCommand(const String argument) : _argument(argument) {}

    inline virtual uint8_t getID(void) override
    {
        return CommandsIDs::PING_COMMAND_ID;
    }

    virtual CmdOutput_t exec(void) override
    {
        if (_argument.length() < 1)
            return {false, "invalid argument length, it should be a non empty string"};

        return {true, String("[pong] ") + _argument};
    }
};