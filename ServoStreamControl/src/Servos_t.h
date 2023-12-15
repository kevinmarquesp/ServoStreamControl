#pragma once

#include <Arduino.h>
#include <ParallelServo.h>

typedef struct Servos_t
{
    ParallelServo* arr;
    uint8_t size;
} Servos_t;
