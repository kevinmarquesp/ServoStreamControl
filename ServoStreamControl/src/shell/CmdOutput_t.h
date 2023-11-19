#pragma once

#include <Arduino.h>

/**
 * This struct is just a base type that the exec function of the command classes
 * can return, note that this has a attribute for the status of the method (if
 * ocured an error on that method or not) and a string for aditional
 * information; It is a good practice to always describe what did wrong or what
 * the method have done.
 *  @attr const bool   isStatusOk: Boolean value that says if the function went wrong or not
 *  @attr const ichar* info:       Aditional information that describes the execution of the function
 */
typedef struct CmdOutput_t
{
    const bool isStatusOk;
    const char* info;
} CmdOutput_t;