#pragma once

#include <Arduino.h>
#include "../shell/BaseCommand.h"
#include "../shell/CmdOutput_t.h"
#include "../shell/CommandsIDs.h"

/**
 * it's just a test to see if the serial comunication is working just fine., and
 * maybe this command will be useful to help server API's know if the sketch
 * was configured to return the expect string.
 */
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

    /**
     * This function just get the argument string and concatenates with a
     * "pong:" prefix. Also, it will throw an error only if the argument string
     * is empty.
     */
    virtual CmdOutput_t exec(void) override
    {
        if (_argument.length() < 1)
            return {false, "invalid argument length, it should be a non empty string"};

        return {true, String("[pong] ") + _argument};
    }
};