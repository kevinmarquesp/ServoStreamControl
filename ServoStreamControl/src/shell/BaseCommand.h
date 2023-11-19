#pragma once

#include <Arduino.h> 
#include "./CmdOutput_t.h"

class BaseCommand
{
public:
    virtual ~BaseCommand() {}

    inline virtual CmdOutput_t execute(void)
    {
        return {false, "execute() method was not implemented for this class"};
    }
};