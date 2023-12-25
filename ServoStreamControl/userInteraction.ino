#include "src/string.h"

namespace userInteraction {
  inline String readSerialInputString(void) {
    while (!Serial.available())
      continue;

    const String userInputString = Serial.readStringUntil('\n');
    string::cleanInputString(userInputString);

    return userInputString;
  }
} // namespace userInteraction