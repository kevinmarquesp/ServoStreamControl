#include <LinkedList.h>
#include <ParallelServo.h>
/* #include "src/strHelpers.h"
#include "src/CmdStatus_t.h" */

LinkedList<ParallelServo> Servos;

/* CmdStatus_t cmdStatus; */
String userSerialInput;
String cmdPrefix, cmdSufix;

/* String readSerialInputString(void);
CmdStatus_t choseAndExecute(const String cmdPrefix, const String cmdSufix); */

void setup(void) {
    Serial.begin(9600);
    delay(1500);
}

void loop(void) {
    /* userSerialInput = readSerialInputString();

    if (!isCommand(userSerialInput)) {
        String errorMessage = userSerialInput + String(" is not a command...");
        printError(errorMessage);

        return;
    }

    userSerialInput = userSerialInput.substring(1);  //remove the '$' char

    divideString(userSerialInput, cmdPrefix, cmdSufix);
    cmdStatus = choseAndExecute(cmdPrefix, cmdSufix);

    if (cmdStatus.isOk)
        printSuccess(cmdStatus.brief);
    else
        printError(cmdStatus.brief); */
}
