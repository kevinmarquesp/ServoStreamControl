#pragma once

#include <Arduino.h> 
#include "./CmdOutput_t.h"
#include "./AvailableCommands.h"

/**
 * Base class that will be extended to form all the other available commands of
 * this interactive serial shell project. About the commands that needs to
 * handle some arguments, these arguments should be passed on a custom
 * constructor that each instance of this class should have - if it's
 * convenient, of course.
 */
class BaseCommand
{
public:
    virtual ~BaseCommand() {}

    /**
     * Each class instance should have this method, it will allow the user to
     * verify if the class that was given to him was the expected one.
     *  @returns uint8_t: A number that is based on the AvailableCommands enum
     */
    inline virtual uint8_t getID(void)
    {
        return AvailableCommands.BASE_COMMAND;
    }

    /**
     * This method should execute some taks and return what it did and if
     * occured an error - maybe you'll want to check the documentation of the
     * CmdOutput_t type. How you can see, this method is meant to be overridden,
     * because it will throws this error if not.
     *  @returns CmdOutput_t: Status of the execution of this method
     */
    inline virtual CmdOutput_t exec(void)
    {
        return {false, "execute() method was not implemented for this class"};
    }
};