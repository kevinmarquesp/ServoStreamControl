#include "src/Servos_t.h"
#include "src/stringUtilities.h"
#include "src/getCommandFromFactory.h"
#include "src/shell/BaseCommand.h"
#include "src/shell/CmdOutput_t.h"

Servos_t Servos;

// As funções abaixo não estão em módulos separados, são arquivos .ino que
// também estão localizados na raíz desse sketch (do lado desse arquivo aqui)
String readUserStringFromSerialInput(void);
void logWhenStatusError(const String msg);
void logWhenStatusOk(const String msg);

void setup(void)
{
    Serial.begin(9600);
    delay(1500);

    Servos.size = 0;
}

void loop(void)
{
    String userInputString = readUserStringFromSerialInput();

    if (!isThisStringAValidCommandString(userInputString))
    {
        logWhenStatusError(userInputString + String(" is not an available command string"));
        return;
    }

    userInputString = userInputString.substring(1);  // remove the '$' character at the begining of the string

    String commandPrefix, commandArguments;
    splitCommandtStringIntoTwoArguments(userInputString, commandPrefix, commandArguments);

    BaseCommand* command = getCommandFromFactory(commandPrefix, commandArguments);
    CmdOutput_t commandOutput = command->exec();

    if (commandOutput.isStatusOk)
        logWhenStatusOk(commandOutput.info);
    else
        logWhenStatusError(commandOutput.info);
}
