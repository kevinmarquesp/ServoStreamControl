#include <LinkedList.h>
#include <ParallelServo.h>

LinkedList<ParallelServo> Servos;

String userSerialInput;
String cmdPrefix, cmdSufix;

void setup(void) {
    Serial.begin(9600);
    delay(1500);
}

void loop(void) {
    userSerialInput = readSerialInputString();
    Serial.println(userSerialInput);
}
