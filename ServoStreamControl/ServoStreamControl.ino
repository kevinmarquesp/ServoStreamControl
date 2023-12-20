#include <LinkedList.h>
#include <ParallelServo.h>

#include "src/stringUtilities.h"
#include "src/status_t.h"

LinkedList<ParallelServo> Servos;

String userSerialInput;
String cmdPrefix, cmdSufix;

void setup(void) {
    Serial.begin(9600);
    delay(1500);
}

void loop(void) {
    userSerialInput = readSerialInputString();
    showInput(userSerialInput);

    status_t commandStringValidation = validateCommandString(userSerialInput);

    if (not commandStringValidation.isOk) {
        showError(commandStringValidation.info);
        return;
    }
}
