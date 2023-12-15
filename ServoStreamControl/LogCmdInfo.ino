inline void logWhenStatusError(const String message)
{
    Serial.print("err : ");
    Serial.println(message);
}

inline void logWhenStatusOk(const String message)
{
    Serial.print(" ok : ");
    Serial.println(message);
}
