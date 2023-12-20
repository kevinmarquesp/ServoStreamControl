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

    typedef struct test_t {
        char* message;
    } test_t;

    test_t test = {"Hello from a char* string!"};
    Serial.println(test.message);
}

void loop(void) {
    return;

    userSerialInput = readSerialInputString();
    Serial.println(userSerialInput);

    /* if (!isCommand(userSerialInput)) {
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
