#include <stringUtilities.h>

// lembrando que a string que o usuário especificou já será validada, ou não,
// pela função `isThisStringAValidCommandString()` desse mesmo módulo, não há a
// necessidade de testes muito complicados por aqui...

test(__splitCommandStringIntoTwoArguments__, should_split_the_string_by_the_colon_character)
{
    String prefixString, argumentsString;

    splitCommandtStringIntoTwoArguments(String("hello:world"), prefixString, argumentsString);

    assertEqual(String("hello"), prefixString);
    assertEqual(String("world"), argumentsString);
}

test(__splitCommandStringIntoTwoArguments__, should_asign_a_empty_string_for_input_strings_without_colon)
{
    String prefixString, argumentsString;

    splitCommandtStringIntoTwoArguments(String("hello"), prefixString, argumentsString);

    assertEqual(String("hello"), prefixString);
    assertEqual(String(""), argumentsString);
}
