#pragma once

#include <Arduino.h>

typedef struct CmdOutput_t
{
    const bool isStatusOk;
    const char* info;
} CmdOutput_t;