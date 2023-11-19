#pragma once

#include <Arduino.h>
#include "../shell/BaseCommand.h"
#include "../shell/CmdOutput_t.h"

class PingCommand : public BaseCommand
{
private:
    String _arg;

public:
    PingCommand(const String arg) : _arg(arg) {}

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