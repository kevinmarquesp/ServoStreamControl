#pragma once

#include <Arduino.h>
#include "Command.h"

/**
 * todo: explain what this command does
 */
class PingCommand : public Command
{
public:
    CommandOutput run(String argument) override {
        return new CommandOutput{ String("pong").concat(argument), 0 };
    }
};