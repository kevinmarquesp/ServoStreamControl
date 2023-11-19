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
    String userInput = readUserStringFromSerialInput();

    if (!isThisStringAValidCommandString(userInput))
    {
        userInput.concat(" is not an available command string");
        logWhenStatusError(userInput);
        return;
    }

    String cmd, arg;
    userInput = userInput.substring(1);  // remove the '$' character at the begining of the string

    spliCommandtStringIntoTwoArguments(userInput, cmd, arg);

    BaseCommand* command = commandFactory(cmd, arg);
    CmdOutput_t commandOutput = command->exec();

    if (commandOutput.isStatusOk)
        logWhenStatusOk(commandOutput.info);
    else
        logWhenStatusError(commandOutput.info);
}