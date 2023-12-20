inline void showInput(const String input) {
    Serial.print(" in : ");
    Serial.println(input);
    Serial.println("    :");
}

inline void showError(const char* info) {
    Serial.print("err : ");
    Serial.println(info);
}
