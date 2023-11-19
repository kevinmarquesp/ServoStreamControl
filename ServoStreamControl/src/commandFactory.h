#pragma once

#include <Arduino.h>
#include "./shell/BaseCommand.h"
#include "../commands/PingCommand.h"

/**
 * Factory that will return the correspondent command class object (a pointer
 * instance) to the user, given the cmd string. If the command doesn't exists,
 * it will return a instance of the BaseCommand class, so the user should have
 * the duty to check for the command type and handle any possible errors.
 *  @param const String cmd: Command identifier, will be used to know wich class this factory should pick
 *  @param const String arg: Some command classes will require the argument string of the command
 */
inline BaseCommand* commandFactory(const String cmd, const String arg = "")
{
    if (cmd.equals("ping"))
        return new PingCommand(arg);
    
    else
        return new BaseCommand();
}