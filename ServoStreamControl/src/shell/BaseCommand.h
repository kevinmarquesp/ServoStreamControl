#pragma once

#include <Arduino.h> 
#include "./CmdOutput_t.h"
#include "./CommandsIDs.h"

class BaseCommand
{
public:
    virtual ~BaseCommand() {}

    inline virtual uint8_t getID(void)
    {
        return CommandsIDs::BASE_COMMAND_ID;
    }

    inline virtual CmdOutput_t exec(void)
    {
        return {false, "execute() method was not implemented for this class"};
    }
};
