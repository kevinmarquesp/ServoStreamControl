#pragma once

#include <Arduino.h>
#include "./TypeAliases.h"

/**
 * todo: add a documentation for that class template
 */
class command
{
public:
    u8 status = 0;

    /**
     * todo: add a documentation for that method
     */
    virtual bool run(void);
};