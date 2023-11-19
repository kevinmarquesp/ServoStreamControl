#pragma once

#include <Arduino.h>

/**
 * Enum that stores an ID, if you will, of each available command. It will be
 * used to check if the given command was the expected one - mainly on the test
 * cases.
 */
enum CommandsIDs
{
    BASE_COMMAND_ID,
    PING_COMMAND_ID,
};