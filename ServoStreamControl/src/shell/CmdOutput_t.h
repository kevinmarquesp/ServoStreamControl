#pragma once

#include <Arduino.h>

typedef struct CmdOutput_t
{
    const bool isStatusOk;
    const String info;
} CmdOutput_t;