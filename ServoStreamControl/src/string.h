#pragma once

#include <Arduino.h>
#include "status_t.h"

inline void _removeRpeatedCharacter(const String& userInputString, char c) {
  char prev = '\0';
  char curr;

  for (uint8_t i = 0; i < userInputString.length(); ++i) {
    curr = userInputString.charAt(i);

    if (curr == c && prev == c) {
      userInputString.remove(i, 1);
      --i;
    }

    prev = curr;
  }
}

namespace string {
  inline void cleanInputString(const String& userInputString) {
    userInputString.toLowerCase();
    userInputString.trim();

    // this part of the code is responsible to remove some repeated characters
    const uint8_t SNUM = 5;
    const char sep[SNUM] = {' ', '-', ',', ':', '/'};

    for (uint8_t i = 0; i < SNUM; ++i)
      _removeRpeatedCharacter(userInputString, sep[i]);
  }
}