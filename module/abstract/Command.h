#pragma once

#include <Arduino.h>

/**
 * todo: explain were this strict is used
 */
typedef struct CommandOutput
{
    String message;
    uint8_t status;
} CommandOutput;

/**
 * todo: explain what this interface does
 */
class Command
{
public:
    virtual ~Command() {}
    virtual CommandOutput run(String argument) {}
};