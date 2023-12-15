#pragma once

#include <Arduino.h>
#include <StringSplitter.h>
#include "../Servos_t.h"
#include "../shell/BaseCommand.h"
#include "../shell/CmdOutput_t.h"
#include "../shell/CommandsIDs.h"

extern Servos_t Servos;

class AttachCommand : public BaseCommand
{
private:
    String _argument;

    inline uint8_t _countCommaCharacters(void)
    {
        uint8_t counter = 0;
        char pastChar = '\0';

        for (uint8_t itr = 0; itr < _argument.length(); ++itr)
        {
            if (_argument.charAt(itr) == ',' && pastChar != ',')
                ++counter;

            if (itr == _argument.length() - 1 && _argument.charAt(itr) != ',')
                ++counter;

            pastChar = _argument.charAt(itr);
        }

        return counter;
    }

public:
    AttachCommand(const String argument) : _argument(argument) {}

    inline virtual uint8_t getID(void) override
    {
        return CommandsIDs::ATTACH_COMMAND_ID;
    }

    inline virtual CmdOutput_t exec(void) override
    {
        //1: count how much ',' characters the string has
            //1: verify the character behind each case
            //2: sum +1 if the string also ends with ','
        //2: split that string by that given number
        //3: convert to an uint8_t array
        //4: write that values to the Servos.arr

        return {true, "hey"};
    }
};
