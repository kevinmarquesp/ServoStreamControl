#include <LinkedList.h>
#include <ParallelServo.h>

String readSerialInputString(void);
void showInput(const char*);
void showInput(const String);
void showError(const char*);
void showError(const String);

LinkedList<ParallelServo> Servos;

String userSerialInput;

void setup(void) {
  Serial.begin(9600);
  delay(1500);
}

void loop(void) {
  userSerialInput = readSerialInputString();

  // ignores if the string is empty...
  if (userSerialInput.length() == 0)
    return;
  showInput(userSerialInput);
}
