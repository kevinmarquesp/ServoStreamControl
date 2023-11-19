#pragma once

#include <Arduino.h>
#include "../shell/BaseCommand.h"
#include "../shell/CmdOutput_t.h"
#include "../shell/AvailableCommands.h"

/**
 * it's just a test to see if the serial comunication is working just fine., and
 * maybe this command will be useful to help server API's know if the sketch
 * was configured to return the expect string.
 */
class PingCommand : public BaseCommand
{
private:
    String _arg;

public:
    PingCommand(const String arg) : _arg(arg) {}

    inline virtual uint8_t getID(void) override
    {
        return AvailableCommands.PING_COMMAND;
    }

    /**
     * This function just get the argument string and concatenates with a
     * "pong:" prefix. Also, it will throw an error only if the argument string
     * is empty.
     */
    virtual CmdOutput_t exec(void) override
    {
        if (this->_arg.length() < 1)
            return {false, "invalid argument length, it should be a non empty string"};

        const String pongString = String("pong:") + this->_arg;
        const char pongCharArr[pongString.length() + 1];

        pongString.toCharArray(pongCharArr, sizeof(pongCharArr));

        return {true, pongCharArr};
    }
};