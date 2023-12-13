#include <stringUtilities.h>

test(__isThisStringAValidCommandString__, should_return_false_for_not_prefixed_commands)
{
    assertTrue(isThisStringAValidCommandString("$hello"));
    assertTrue(isThisStringAValidCommandString("$hello:world"));
    assertTrue(isThisStringAValidCommandString("$H"));

    assertFalse(isThisStringAValidCommandString("hello"));
    assertFalse(isThisStringAValidCommandString("hello:world"));
    assertFalse(isThisStringAValidCommandString("$"));
}

test(__isThisStringAValidCommandString__, should_return_false_for_invalid_command_formats)
{
    assertFalse(isThisStringAValidCommandString("$:"));
    assertFalse(isThisStringAValidCommandString("$:hello"));
    assertFalse(isThisStringAValidCommandString("$hello world"));
    assertFalse(isThisStringAValidCommandString(" $hello"));
}
