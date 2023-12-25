inline void showInput(const char* input) {
  showInput(String(input));
}

inline void showInput(const String input) {
  Serial.print(" in : ");
  Serial.println(input);
}

inline void showError(const char* info) {
  showError(String(info));
}

inline void showError(const String info) {
  Serial.print("err : ");
  Serial.println(info);
}
