#include <LinkedList.h>
#include <ParallelServo.h>

String userInteraction::readSerialInputString(void);
void userDisplay::showInput(const char*);
void userDisplay::showInput(const String);
void userDisplay::showError(const char*);
void userDisplay::showError(const String);

LinkedList<ParallelServo> Servos;

String userSerialInput;

void setup(void) {
  Serial.begin(9600);
  delay(1500);
}

void loop(void) {
  userSerialInput = userInteraction::readSerialInputString();

  // ignores if the string is empty...
  if (userSerialInput.length() == 0)
    return;

  userDisplay::showInput(userSerialInput);
}
