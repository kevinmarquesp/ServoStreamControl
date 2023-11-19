#include <ParallelServo.h>
#include "src/stringUtilities.h"
#include "src/commandFactory.h"
#include "src/shell/BaseCommand.h"
#include "src/shell/CmdOutput_t.h"

String readUserStringFromSerialInput(void);
void logWhenStatusError(const String msg);
void logWhenStatusOk(const String msg);

void setup(void)
{
    Serial.begin(9600);
    delay(1500);
}

void loop(void)
{
    String userInputString = readUserStringFromSerialInput();

    if (!isThisStringAValidCommandString(userInputString))
    {
        userInputString.concat(" is not an available command string");
        logWhenStatusError(userInputString);

        return;
    }

    String commandPrefix, commandArguments;
    userInputString = userInputString.substring(1);  // remove the '$' character at the begining of the string

    spliCommandtStringIntoTwoArguments(userInputString, commandPrefix, commandArguments);

    BaseCommand* command = commandFactory(commandPrefix, commandArguments);
    CmdOutput_t commandOutput = command->exec();

    if (commandOutput.isStatusOk)
        logWhenStatusOk(commandOutput.info);
    else
        logWhenStatusError(commandOutput.info);
}